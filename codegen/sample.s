.text

####INSIDE FUNCTION
_foo: 
push %ebp
mov %esp, %ebp
sub $4,%esp
pop %ebx
push %ebx
#### Param Visited
popl %eax
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
sub $4,%esp
#### visitFuncBlock
#### VISIT Decl
####VISIT CALL
#### Visit INT
pushl $100
call _foo
movl %eax, -4(%ebp)
#### Visit ID
pushl -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
