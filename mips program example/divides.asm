
lis $3
.word 1
divu $2, $1
mfhi $8
beq $8, $0, 1
add $3, $0, $0
jr $31