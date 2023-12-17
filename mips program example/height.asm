lis $4
.word 1
lis $5
.word -1
lis $21
.word getHeight
lis $19
.word 4
add $20, $0, $1
lis $22
.word 0xFFFF000c
lis $23
.word 48

lis $18
.word -4
add $18, $18, $20

getHeight:
    sw $1, -4($30)
    sw $6, -8($30)
    sw $7, -12($30)
    sw $8, -16($30)
    sw $9, -20($30)
    sw $10, -24($30)
    sw $11, -28($30)
    sw $12, -32($30)
    sw $15, -36($30)
    sw $31, -40($30)

    lis $31
    .word 40
    sub $30, $30, $31

    add $3, $0, $0
    beq $1, $18, end

    ; left right child
    add $6, $1, $19
    add $7, $6, $19

    lw $1, 0($6)
    add $1, $1, $1
    add $1, $1, $1
    add $1, $1, $20
    jalr $21
    add $9, $0, $3

    ; right child
    lw $1, 0($7)
    add $1, $1, $1
    add $1, $1, $1
    add $1, $1, $20
    jalr $21
    add $10, $0, $3

    ; max
    slt $11, $9, $10
    sub $12, $4, $11
    mult $11, $10
    mflo $11
    mult $12, $9
    mflo $12
    add $11, $11, $12

    add $3, $4, $11

end:
    lis $31
    .word 40
    add $30, $30, $31
    lw $1, -4($30)
    lw $6, -8($30)
    lw $7, -12($30)
    lw $8, -16($30)
    lw $9, -20($30)
    lw $10, -24($30)
    lw $11, -28($30)
    lw $12, -32($30)
    lw $15, -36($30)
    lw $31, -40($30)
    jr $31