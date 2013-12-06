.text

####INSIDE FUNCTION
_foo: 
push %ebp
mov %esp, %ebp
sub $8,%esp
#### Param Visited
mov 8(%ebp), %eax
mov %eax, -4(%ebp)
#### Param Visited
mov 12(%ebp), %eax
mov %eax, -8(%ebp)
#### visitFuncBlock
#### PLUS
pushl $0
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
pushl $111
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
