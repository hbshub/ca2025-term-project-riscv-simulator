import os
import re
import shutil
import subprocess
import shlex
import logging
import random
import string
from string import Template

import riscof.utils as utils
from riscof.pluginTemplate import pluginTemplate
import riscof.constants as constants

logger = logging.getLogger()

# [Mod1] Rename sail_plugin to spike_plugin
class spike(pluginTemplate):
    __model__ = "spike"
    __version__ = "1.0.0"

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        config = kwargs.get('config')
        if config is None:
            logger.error("Config node for spike missing.")
            raise SystemExit(1)
        # [Mod2] Set riscv_prefix for cross-compilation tools
        self.riscv_prefix = config['riscv_prefix'] if 'riscv_prefix' in config else 'riscv-none-elf-'
        self.num_jobs = str(config['jobs'] if 'jobs' in config else 1)
        self.pluginpath = os.path.abspath(config['pluginpath'])
        
        # [Mod3] Rename sail_exe and set spike executable paths
        self.spike_exe = os.path.join(config['PATH'] if 'PATH' in config else "","spike")
        
        self.isa_spec = os.path.abspath(config['ispec']) if 'ispec' in config else ''
        self.platform_spec = os.path.abspath(config['pspec']) if 'ispec' in config else ''
        self.make = config['make'] if 'make' in config else 'make'
        logger.debug("Spike plugin initialised using the following configuration.")
        for entry in config:
            logger.debug(entry+' : '+config[entry])

    def initialise(self, suite, work_dir, archtest_env):
        self.suite = suite
        self.work_dir = work_dir
        # [Mod4] Use riscv_prefix for objdump and gcc commands
        self.objdump_cmd = self.riscv_prefix + 'objdump -D {0} > {2};'
        self.compile_cmd = self.riscv_prefix + 'gcc -march={0} \
         -static -mcmodel=medany -fvisibility=hidden -nostdlib -nostartfiles\
         -T '+self.pluginpath+'/env/link.ld\
         -I '+self.pluginpath+'/env/\
         -I ' + archtest_env

    def build(self, isa_yaml, platform_yaml):
        ispec = utils.load_yaml(isa_yaml)['hart0']
        self.xlen = ('64' if 64 in ispec['supported_xlen'] else '32')
        self.isa_yaml_path = isa_yaml
        self.isa = 'rv' + self.xlen
        self.compile_cmd = self.compile_cmd+' -mabi='+('lp64 ' if 64 in ispec['supported_xlen'] else 'ilp32 ')
        if "I" in ispec["ISA"]:
            self.isa += 'i'
        if "M" in ispec["ISA"]:
            self.isa += 'm'
        if "A" in ispec["ISA"]:
            self.isa += 'a'
        if "F" in ispec["ISA"]:
            self.isa += 'f'
        if "D" in ispec["ISA"]:
            self.isa += 'd'
        if "C" in ispec["ISA"]:
            self.isa += 'c'
        # [Mod5] Delete sail env related and check for spike executable
        if shutil.which(self.spike_exe) is None:
            logger.error(self.spike_exe+ ": executable not found. Please check environment setup.")
            raise SystemExit(1)
    
    # [Mod6] Rewrite runTests method for spike simulation
    def runTests(self, testList):
        
        for testname in testList:
            testentry = testList[testname]
            test = testentry['test_path']
            test_dir = testentry['work_dir']

            elf = 'ref.elf'
            sig_file = os.path.join(test_dir, self.name[:-1] + ".signature")

            # Compile
            cmd = self.compile_cmd.format(testentry['isa'].lower(), self.xlen) + ' ' + test + ' -o ' + elf
            compile_cmd = cmd + ' -D' + " -D".join(testentry['macros'])
            utils.shellCommand(compile_cmd).run(cwd=test_dir)

            # Execute
            spike_cmd = '{0} --isa={1} +signature={2} +signature-granularity=4 {3}'.format(
                self.spike_exe, self.isa, sig_file, elf
            )
            utils.shellCommand(spike_cmd).run(cwd=test_dir)
