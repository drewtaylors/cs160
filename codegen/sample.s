.text

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $4,%esp
#### visitFuncBlock
#### VISIT Decl
#### PLUS
#### Uminus
#### Visit INT
pushl $5
 popl %eax
 negl %eax
 pushl %eax
#### Uminus
#### Visit INT
pushl $10
 popl %eax
 negl %eax
 pushl %eax
popl %ebx
popl %eax
addl %ebx, %eax
pushl %eax
 popl %eax
cdq
xorl %edx, %eax
 subl %edx, %eax
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
