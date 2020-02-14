	.data
name: 	.space 41
prompt: .asciiz "Enter your name (FIRST LAST): *** user input : "
reverse: .asciiz " reversed is: "
comma: .asciiz ", "

	.text
	.globl main
main:
	li $v0, 4
	la $a0, prompt	
	syscall		#displays the input prompt
	
	li $v0, 8	#creates input stores in address v0
	la $a0, name	
	li $a1, 41	#creates input for 41 chars
	syscall
	
	la $t0, name
	li $t7, '\n'
	
loop1: 
	lb $t1, ($t0)	
	#beqz $t1, Exit
	beq $t1, $t7, exitloop1
	lb $a0, ($t0)
	li $v0, 11
	syscall
	addiu $t0, $t0, 1
j loop1
exitloop1:
	li $v0, 4
	la $a0, reverse
	syscall		#sisplays the reverse prompt

	la $t0, name
	li $t6, ' '			
	#########################
	#lb $t1,($a0)
	#li $v0, 11
	#syscall
	#addi $a1, $a1, 1
	#lb $a0, 0($a1)
	#li $v0, 11
	#syscall
	##########################
	
loop2:				# Skip First name
	lb $t1, ($t0)	
	beq $t1, $t6, loop3 
	addiu $t0, $t0, 1	
j loop2	

loop3:				# Print Last Name
	addiu $t0, $t0, 1	
	lb $t1, ($t0)	
	
	beq $t1, $t7, exitloop3 
	lb $a0, ($t0)
	li $v0, 11
	syscall
j loop3
exitloop3:
	li $v0, 4
	la $a0, comma
	syscall		#displays the comma prompt
	
	la $t0, name	#Resetting String
	li $t6, ' '
loop4:
	lb $t1, ($t0)	
	beq $t1, $t6, exitloop4 
	lb $a0, ($t0)
	li $v0, 11
	syscall
	addiu $t0, $t0, 1	
j loop4
exitloop4:
	

	li $v0, 10
	syscall
