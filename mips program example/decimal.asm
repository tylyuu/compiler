lis $1
.word 0xFFFF0004
lis $2
.word 0xFFFF000c

; store 1 if neg, otherwise 0
lis $3
.word 0

lis $4
.word 0

lis $5
.word 45

lis $6
.word 10

lis $7
.word 0x0A

lis $8
.word 0

lis $9
.word 1

lis $10
.word 0x30

lis $11
.word 2

lis $12
.word 256



loop:
    lw $8, 0($1)
    beq $8, $5, add1
    beq $8, $7, final
    sub $8, $8, $10
    mult $4, $6
    mflo $4
    add $4, $4, $8
    beq $0, $0, loop
    

add1:
    lis $3
    .word 1
    beq $0, $0, loop


final:
    beq $3, $9, neg
    beq $0, $0, done

neg:
    sub $4, $12, $4
    beq $0, $0, done


done:
    sw $4, 0($2)
    jr $31


