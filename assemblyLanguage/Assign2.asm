############################ data segment ################################
	.data 
prompt:	.asciiz "Enter your name (format 'FIRST LAST'): "
done:	.asciiz "\nThanks for playing\n"
name:	.space  101 # array of 101 bytes 
############################ code segment ################################ 
	.text 
	.globl main
main:	la $a0, prompt
	li $v0, 4
	syscall
	la $a0, name
	li $a1, 101
	li $v0, 8
	syscall

	la $a1, name
	li $t1, 58
	li $t2, 32
loopin:	li $v0, 1
	lbu $a0, ($a1)
	blt $a0, $t2, loopout
	beq $a0, $zero, loopout
	ori $t0, $a0, 0

	li $v0, 11
	andi $a0, $t0, 0x0F
	addi $a0, $a0, 0x30
	blt $a0, $t1, print1
	addi $a0, $a0, 7
print1:	syscall	
	
	srl $a0, $t0, 4
	addi $a0, $a0, 0x30
	blt $a0, $t1, print2
	addi $a0, $a0, 7
print2: syscall
	
	addi $a1, $a1, 1
	j loopin

loopout:
	la $a0, done 
	li $v0, 4
	syscall

	li $v0, 10
	syscall
