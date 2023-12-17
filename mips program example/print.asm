


print:

    sw $1, -4($30)
    sw $2, -8($30)
    sw $3, -12($30)
    sw $4, -16($30)
    sw $5, -20($30)
    sw $6, -24($30)
    sw $7, -28($30)
    sw $8, -32($30)
    sw $9, -36($30)
    sw $10, -40($30)
    sw $11, -44($30)
    sw $12, -48($30)
    sw $13, -52($30)
    sw $14, -56($30)
    sw $15, -60($30)
    sw $16, -64($30)
    lis $16
    .word 64
    sub $30, $30, $16

    lis $3
    .word 10
    lis $8
    .word 1
    lis $9
    .word 4
    lis $6
    .word 0
    lis $15
    .word 0x30
    lis $10
    .word 0
    lis $14
    .word 0xFFFF000c
    lis $13
    .word 0x0A

    beq $1, $0, printzero

    main:
        slt $12, $0, $1
        bne $12, $0, notneg2
            lis $4
            .word 0x2D
            sw $4, 0($14)
        notneg2:
            beq $0, $0, loop2

    printzero:
        lis $3
        .word 0x30
        sw $3, 0($14)
        beq $0, $0, end

    loop2:
      ;  sw $1, 0($14)
        beq $1, $0, loop3
        div $1, $3
        mfhi $7

        bne $12, $0, notneg
            sub $7, $0, $7
        notneg:
            sw $7, -4($30)
          ;  sw $7, 0($14)
            sub $30, $30, $9
            add $6, $6, $9
            mflo $7
            add $1, $0, $7
            beq $0, $0, loop2
    
    loop3:
        slt $11, $10, $6
        beq $11, $0, end
        add $30, $30, $9
        lw $7, -4($30)
        add $7, $7, $15
        sw $7, 0($14)
        add $10, $10, $9
        beq $0, $0, loop3
    
    end:
        sw $13, 0($14)
        add $30, $30, $16
        lw $1, -4($30)
        lw $2, -8($30)
        lw $3, -12($30)
        lw $4, -16($30)
        lw $5, -20($30)
        lw $6, -24($30)
        lw $7, -28($30)
        lw $8, -32($30)
        lw $9, -36($30)
        lw $10, -40($30)
        lw $11, -44($30)
        lw $12, -48($30)
        lw $13, -52($30)
        lw $14, -56($30)
        lw $15, -60($30)
        lw $16, -64($30)
        jr $31





        
        
        
        





    