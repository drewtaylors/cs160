.text

_foo: 
push %ebp
mov %esp, %ebp
sub $0,%esp
#### visitFuncBlock
#### Visit INT
pushl $9
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret

.global Main
Main:
push %ebp
mov %esp, %ebp
#### visitFuncBlock
#### VISIT Decl
####VISIT CALL
call _foo
movl %eax, -4(%ebp)
#### Visit ID
pushl -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
