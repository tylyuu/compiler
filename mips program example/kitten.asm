lis $1
.word 0xFFFF0004
lis $2
.word 0xFFFF000c
lis $3
.word 0
lis $4
.word 1
lw $8, 0($1)
top:
    slt $9, $8, $0
    beq $9, $4, end
    sw $8, 0($2)
    add $3, $3, $4
    lw $8, 0($1)
    bne $9, $4, top

end:
    jr $31



