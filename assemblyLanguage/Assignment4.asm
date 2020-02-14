##########################################################################
# Nathan Perkins, CS 2318 Assignment 4
##########################################################################
# Recursively Multiplies
############################ data segment ################################
		.data

prompt_1:	.asciiz "Enter the multiplicand: "		
prompt_2:	.asciiz "Enter the multiplier: "
multSign:	.asciiz " * "
eqSign:		.asciiz " = "
############################ code segment ################################
		.text
		.globl main		
main:
		###########################################################
		############## Prompt and store Multiplicand ##############
		li $v0, 4
		la $a0, prompt_1
		syscall
		
		li $v0, 5		# Read Int into $v0
		syscall
		
		move $t0, $v0		# Store Multiplicand into $t0
		###########################################################
		############### Prompt and store Multiplier ###############
		li $v0, 4
		la $a0, prompt_2
		syscall
		
		li $v0, 5		# Read Int into $v0
		syscall
		
		move $t1, $v0		# Store Multiplier into $t1
		add $t2, $t2, $t1	# For preserving $t1 value after indexing
		
		###########################################################
		################### Recursively Function ##################
		li $t7, 1	# $t7 = 1
		add $t3, $t3, $t0
repeatAdd:
		#1# 	if ($t0 <= 0 || $t1 <= 0)
		#2#		return 0;
		#3#
		#4#	else if ($t0 == 1)
		#5#		return $t1;
		#6# 	else
		#7# 		return repeatAdd($t0-1, $t1)
		
		
		# if ($t0 <= 0 || $t1 <= 0)
		beqz $t0, recursionFinished
		beqz $t1, recursionFinished
		
		# else if ($t1 == 1)
		beq $t1, $t7, recursionFinished
		
		# else
		add $t3, $t3, $t0
		addiu $t1, $t1, -1	# $t1--
		j repeatAdd
recursionFinished:
		###########################################################
		########################## Print ##########################
		move $a0, $t0
		li $v0, 1		# Print Multiplicand
		syscall
		
		li $v0, 4
		la $a0, multSign	# Print " * "
		syscall
			
		move $a0, $t2
		li $v0, 1		# Print Multiplier	
		syscall
		
		li $v0, 4
		la $a0, eqSign		# Print " = "
		syscall	
		
		move $a0, $t3
		li $v0, 1		# Print Answer
		syscall
		###########################################################	
                ########################## Exit ###########################
		li $v0, 10
		syscall	
