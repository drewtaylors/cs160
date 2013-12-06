.text

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $400,%esp
#### visitFuncBlock
#### VISIT Decl
#### Visit INT
pushl $10
#### ARRAY ASSIGN
popl %eax
mov %eax, -4(%ebp)
#### Visit ArrayAccess
#### Visit INT
pushl $1
pop %eax
push -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
