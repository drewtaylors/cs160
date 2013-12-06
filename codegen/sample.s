.text

####INSIDE FUNCTION
_test: 
push %ebp
mov %esp, %ebp
sub $4,%esp
#### Param Visited
mov 8(%ebp), %eax
mov %eax, -4(%ebp)
#### visitFuncBlock
#### Visit ID
pushl -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $20,%esp
#### visitFuncBlock
#### Visit INT
pushl $100
#### ARRAY ASSIGN
popl %eax
mov %eax, -12(%ebp)
#### Visit ArrayAccess
#### Visit INT
pushl $3
pop %eax
push -12(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
