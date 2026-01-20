.section .text
.global _start
.global run_q1_uf8

# ==========================================
# 1. Entry Point
# ==========================================
_start:
    jal  ra, run_q1_uf8  # call core test function, result in a0

    # ============================================
    # a0 already contains the return value from run_q1_uf8 (1=Pass, 0=Fail)
    # ============================================
    li   a7, 93          # Syscall number 93 = exit
    ecall                # Trigger syscall, emulator will catch this and print a0

# ==========================================
# 2. Core Test Function
# ==========================================
run_q1_uf8:
    addi sp, sp, -16
    sw   ra, 12(sp)
    
    # Initialize variables
    li   s0, 0            # s0 = i (current index)
    li   s1, -1           # s1 = previous_value (for monotonicity check)
    li   s2, 256          # s2 = Remaining count (loop 256 times)
    li   s3, 1            # s3 = Passed flag (default to 1: Pass)
    
    jal  test             # Execute test loop

    # Restore ra
    lw   ra, 12(sp)
    mv   a0, s3           # move final result from s3 to a0 
    addi sp, sp, 16
    ret 

# ==========================================
# 3. Test Loop
# ==========================================
test:
    addi sp, sp, -16
    sw   ra, 12(sp)

loop:
    beqz s2, test_end     # If count == 0, end
    andi a0, s0, 255      # a0 = i

    # --- Inlined uf8_decode ---
    srli t0, a0, 4        
    andi a0, a0, 0x0F     
    addi a0, a0, 16       
    sll  a0, a0, t0       
    addi a0, a0, -16
    # --------------------------

    addi s4, a0, 0        # s4 = decoded value
    jal  uf8_encode       # Call encode
    andi a0, a0, 255      # Mask result to 8 bits

    # --- Verification Logic ---
    # Check if encode(decode(i)) == i
    bne  s0, a0, mark_fail
    j    check_mono_inc

mark_fail:
    li   s3, 0            # Set flag to 0 (Fail)
    
check_mono_inc:
    # Check monotonicity: current_value (s4) >= previous_value (s1)
    blt  s4, s1, set_fail_mono 
    j    update_state

set_fail_mono:
    li   s3, 0            # Set flag to 0 (Fail)

update_state:
    addi s1, s4, 0        # previous_value = current_value
    addi s0, s0, 1        # i++
    addi s2, s2, -1       # count--
    j    loop

test_end:
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret

# ==========================================
# 4. Encoder
# ==========================================
uf8_encode:
    li  t3, 16
    bge a0, t3, e_not_zero         
    ret
e_not_zero:
    addi sp, sp, -16      
    sw   ra, 12(sp)       
    mv   t4, a0           
    jal  ra, clz          
    li   t3, 31
    sub  t0, t3, a0       
    mv   a0, t4           
    lw   ra, 12(sp)       
    addi sp, sp, 16       
    
    li t1, 0                
    li t2, 0                
    li   t3, 5
    blt  t0, t3, find_exa_exp         
    addi t1, t0, -4               
    sltiu t3, t1, 16
    beqz  t3, set_exp_15    
    j     build_of_once
set_exp_15:
    li    t1, 15          
build_of_once:
    li   t2, 1
    sll  t2, t2, t1       
    addi t2, t2, -1       
    slli t2, t2, 4        
    j    adj_exp          
adj_exp:
    ble  t1, x0, find_exa_exp        
    bge  a0, t2, find_exa_exp         
    addi t2, t2, -16                
    srli t2, t2, 1                  
    addi t1, t1, -1                 
    j    adj_exp
find_exa_exp:
    li   t6, 15
    bge  t1, t6, calc_m          
    slli t0, t2, 1               
    addi t0, t0, 16              
    blt  a0, t0, calc_m          
    mv   t2, t0                  
    addi t1, t1, 1               
    j    find_exa_exp
calc_m:
    sub t0, a0, t2               
    srl t0, t0, t1              
    li  t6, 15
    ble t0, t6, cmb_num        
    li  t0, 15                   
cmb_num:    
    slli t1, t1, 4               
    or   a0, t1, t0              
    ret

# ==========================================
# 5. Helper (clz)
# ==========================================
clz:
    beq   a0, x0, clz_zero
    li    t0, 0
    srli  t1, a0, 16            
    bnez  t1, check_8_bits      
    addi  t0, t0, 16            
    slli  a0, a0, 16            
check_8_bits:
    srli  t1, a0, 24            
    bnez  t1, check_4_bits      
    addi  t0, t0, 8             
    slli  a0, a0, 8             
check_4_bits:
    srli  t1, a0, 28            
    bnez  t1, check_2_bits      
    addi  t0, t0, 4             
    slli  a0, a0, 4             
check_2_bits:
    srli  t1, a0, 30            
    bnez  t1, check_1_bit       
    addi  t0, t0, 2             
    slli  a0, a0, 2             
check_1_bit:
    srli  t1, a0, 31            
    bnez  t1, clz_finish        
    addi  t0, t0, 1             
clz_finish:
    mv    a0, t0                
    ret
clz_zero:
    li    a0, 32                
    ret