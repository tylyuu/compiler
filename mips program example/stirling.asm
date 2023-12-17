
stirling:
    ; n
    sw $1, -4($30)
    ; k
    sw $2, -8($30)
    ; 1
    sw $4, -12($30)
    ; temp1
    sw $5, -16($30)
    ; temp2
    sw $7, -20($30)
    ; $31
    sw $31, -24($30)
    lis $31
    .word 24
    sub $30, $30, $31

    lis $4
    .word 1
    lis $7
    .word 0

    lis $3
    .word 1

    ; if both of them is 0
    add $7, $1, $2
    beq $7, $0, end

    lis $3
    .word 0
    
    ; if one of them is 0
    mult $1, $2
    mflo $7
    beq $7, $0, end

    lis $3
    .word stirling
    ; n-1
    sub $1, $1, $4
    jalr $3
    mult $1, $3
    mflo $5
    ; k-1
    sub $2, $2, $4
    lis $3
    .word stirling
    jalr $3
    add $3, $3, $5

end:
    lis $31
    .word 24
    add $30, $30, $31
    lw $1, -4($30)
    lw $2, -8($30)
    lw $4, -12($30)
    lw $5, -16($30)
    lw $7, -20($30)
    lw $31, -24($30)
    jr $31











