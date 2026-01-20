.section .text
.global _start
.global run_q1_uf8

.option rvc

# ==========================================
# 1. Entry Point
# ==========================================
_start:
    jal  ra, run_q1_uf8
    li   a7, 93
    ecall
    unimp

# ==========================================
# 2. Core Function
# ==========================================
run_q1_uf8:
    addi sp, sp, -16
    sw   ra, 12(sp)
    
    # s0 (x8) = i (Loop Index)
    # s1 (x9) = Pass Flag
    
    li   s0, 0            # i = 0
    li   s1, 1            # Flag = 1 (Pass)
    
    jal  test

    mv   a0, s1           # move result s1 to a0 for return
    
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret 

# ==========================================
# 3. Test Loop
# ==========================================
test:
    # establish Stack Frame (16 bytes)
    # 12(sp): ra
    #  8(sp): prev_val
    #  4(sp): temp save for decoded_value (a3)
    addi sp, sp, -16
    sw   ra, 12(sp)
    
    # initialize prev_val = -1 to Stack
    li   a4, -1
    sw   a4, 8(sp)

loop:
    li   a4, 256
    beq  s0, a4, test_end # if i == 256, end loop

    mv   a0, s0
    andi a0, a0, 255      # a0 = i

    # --- Inlined uf8_decode ---
    mv   a4, a0           
    srli a4, a4, 4        
    andi a0, a0, 0x0F     
    addi a0, a0, 16       
    # sll can't be compressed, this is necessary 32-bit
    sll  a0, a0, a4       
    addi a0, a0, -16      
    # --------------------------

    # [Key] Before calling uf8_encode, must save important info 
    # decoded_value (a0) must be saved because it will be used to compare with prev_val later
    sw   a0, 4(sp)        # save to stack

    # Call encode (this will clobber a0-a5)
    # s0 (i) and s1 (Flag) are safe
    jal  uf8_encode       
    
    andi a0, a0, 255      # result mask

    # --- Verification 1: Encode(Decode(i)) == i ---
    # a0 (encoded) vs s0 (i)
    sub  a0, a0, s0       # c.sub (destructive: a0 = a0 - s0)
    beqz a0, check_mono   # c.beqz (if difference is 0 -> Pass)
    
    li   s1, 0            # Fail! Set Flag = 0

check_mono:
    # --- Verification 2: Monotonicity ---
    # read decoded_value (current)
    lw   a3, 4(sp)        
    # read prev_val
    lw   a4, 8(sp)        
    
    # check: current (a3) >= prev (a4)
    # blt a3, a4, fail
    blt  a3, a4, set_fail_mono
    j    update_state

set_fail_mono:
    li   s1, 0            # Fail! Set Flag = 0

update_state:
    sw   a3, 8(sp)        # prev_val = current (update stack value)
    addi s0, s0, 1        # i++
    j    loop             # c.j

test_end:
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret

# ==========================================
# 4. Encoder
# ==========================================
uf8_encode:
    li  a4, 16            
    bge a0, a4, e_not_zero         
    ret                   
e_not_zero:
    addi sp, sp, -16      
    sw   ra, 12(sp)       
    sw   a0, 8(sp)        
    jal  ra, clz          
    li   a4, 31           
    sub  a1, a4, a0       
    lw   a0, 8(sp)        
    lw   ra, 12(sp)       
    addi sp, sp, 16       
    li   a2, 0            
    li   a3, 0            
    li   a4, 5            
    blt  a1, a4, find_exa_exp         
    addi a2, a1, -4       
    li   a4, 16
    sltiu a4, a2, 16      
    beqz  a4, set_exp_15  
    j     build_of_once   
set_exp_15:
    li    a2, 15          
build_of_once:
    li   a3, 1            
    sll  a3, a3, a2       
    addi a3, a3, -1       
    slli a3, a3, 4        
    j    adj_exp          
adj_exp:
    ble  a2, x0, find_exa_exp 
    bge  a0, a3, find_exa_exp
    addi a3, a3, -16      
    srli a3, a3, 1        
    addi a2, a2, -1       
    j    adj_exp          
find_exa_exp:
    li   a5, 15           
    bge  a2, a5, calc_m   
    slli a1, a3, 1        
    addi a1, a1, 16       
    blt  a0, a1, calc_m
    mv   a3, a1           
    addi a2, a2, 1        
    j    find_exa_exp
calc_m:
    mv   a1, a0
    sub  a1, a1, a3       
    srl  a1, a1, a2       
    li   a5, 15
    ble  a1, a5, cmb_num
    li   a1, 15           
cmb_num:    
    slli a2, a2, 4        
    or   a0, a2, a1       
    ret

# ==========================================
# 5. Helper (clz)
# ==========================================
clz:
    beq   a0, x0, clz_zero 
    li    a1, 0            
    srli  a2, a0, 16       
    bnez  a2, check_8_bits 
    addi  a1, a1, 16       
    slli  a0, a0, 16       
check_8_bits:
    srli  a2, a0, 24       
    bnez  a2, check_4_bits 
    addi  a1, a1, 8        
    slli  a0, a0, 8        
check_4_bits:
    srli  a2, a0, 28
    bnez  a2, check_2_bits
    addi  a1, a1, 4
    slli  a0, a0, 4
check_2_bits:
    srli  a2, a0, 30
    bnez  a2, check_1_bit
    addi  a1, a1, 2
    slli  a0, a0, 2
check_1_bit:
    srli  a2, a0, 31
    bnez  a2, clz_finish
    addi  a1, a1, 1
clz_finish:
    mv    a0, a1           
    ret                    
clz_zero:
    li    a0, 32           
    ret