.text

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $4,%esp
#### visitFuncBlock
#### OR
 pushl $0
#### ASSIGN
popl %eax
mov %eax, -4(%ebp)
#### Visit ID
pushl -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
