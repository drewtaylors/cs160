.text

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $4,%esp
#### visitFuncBlock
#### VISIT Decl
#### DIVIDE
#### Visit INT
pushl $10
#### Visit INT
pushl $5
 popl %ebx
 popl %eax
 cdq
 idivl %ebx
 pushl %eax
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
