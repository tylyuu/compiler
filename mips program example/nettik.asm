lis $1
.word 0xFFFF0004
lis $2
.word 0xFFFF000c
lis $3
.word 0
lis $4
.word 1
lis $5
.word 0
lis $6
.word 0
add $6, $0, $30
lis $7
.word 4

top:
    lw $8, 0($1)
    slt $9, $8, $0
    beq $9, $4, print
    sw $8, -4($30)
    sub $30, $30, $7
    add $3, $3, $4
    bne $9, $4, top

print:
    lw $8, -4($30)
    add $30, $30, $7
    loop:
        beq $30, $6, end
        lw $8, -4($30)
        sw $8, 0($2)
        add $30, $30, $7
        beq $0, $0, loop

end:
    lw $8, -4($30)
    sw $8, 0($2)
    jr $31



