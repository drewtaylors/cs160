.text

####INSIDE FUNCTION
_foo: 
push %ebp
mov %esp, %ebp
sub $0,%esp
#### visitFuncBlock
#### Visit INT
pushl $5
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $168,%esp
#### visitFuncBlock
####VISIT ARRAY CALL
call _foo
movl %eax, -132(%ebp)
#### Visit ArrayAccess
#### Visit INT
pushl $2
pop %eax
push -132(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
