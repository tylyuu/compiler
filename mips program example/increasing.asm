; addr of array head
add $4, $0, $1

lis $8
.word 4

; array size
add $5, $0, $2


; count
lis $6
.word 1

lis $9
.word 1

lis $21
.word compare

loop:
    beq $6, $5, done
    lw $1, 0($4)
    lw $2, 4($4)
    add $4, $4, $8
    add $6, $6, $9
    sw $31, -4($30)
    sub $30, $30, $8   
    jalr $21
    add $30, $30, $8
    lw $31, -4($30)
    beq $3, $0, done
    beq $3, $9, loop


done:
    jr $31



