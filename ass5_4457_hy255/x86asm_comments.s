# -----------------------------------
# Program x86asm.s
# Compute and print the sum 0+...+N
# -----------------------------------

	.section .data	# The following instructions will initialize the data segment(global variables)
N:	.long 1000	    # N label points to a variable of type long, initialized to value 1000
S:	.long 0		    # S label points to a variable of type long, initialized to value 0
Msg:	.ascii "The sum from 0 to %d is %d\n\0"


	.section .text	# The following instructions will be stored at text segment as machine code, ready to be executed
.globl main
main:	
	pushl %ebp	    # main's stack frame has been created - base stack pointer value gets pushed in stack.
					# Everytime we push something into the stack, the stack pointer gets updated (decremented, as stack grows upwards in memory)
	movl %esp, %ebp	# Value contained in %esp(stack pointer) is copied to %ebp (return address)

 	# initialize
    movl N, %ebx	# value 1000 is copied to %ebx register

 	# compute sum
L1:
	addl %ebx, S	# S := S + %ebx
	decl %ebx       # %ebx := %ebx - 1
	cmpl $0, %ebx   # Compare %ebx value with zero, and store comparison result to internal register
	jng  L2	    	# if(0 <= %ebx) jump to L2 label
    movl $L1, %eax	# L1 label address is copied to %eax
    jmp *%eax   	# jump to the address contained in %eax (L1)

L2:
	# print result
	pushl S	    	# a copy of S value is pushed to stack
	pushl N	        # a copy of N value is pushed to stack
	pushl $Msg  	# a copy of Msg string is pushed to stack
	call printf 	# printf function gets called
	popl %eax   	# Msg string is popped out of the stack. Stack pointer gets updated each time (incremented, as stack grows upwards in memory)
	popl %eax   	# N value is popped out of the stack
	popl %eax   	# S value is popped out of the stack

	# exit
	movl $0, %eax  	# %eax := 0
    leave	    	# Procedure Exit: %ebp value is copied to %esp and %ebp value is popped out of the stack.
 	ret             # Return to the caller (jump to the address contained in %esp)
