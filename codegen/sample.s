.text

_foo: 
push %ebp
mov %esp, %ebp
sub $8,%esp
popl %eax
mov %eax, -4(%ebp)
#### visitFuncBlock
#### VISIT Decl
#### PLUS
pushl $20
#### ASSIGN
popl %eax
mov %eax, -8(%ebp)
#### Visit ID
pushl $20
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
pushl $10
call _foo
movl %eax, -4(%ebp)
#### Visit ID
pushl -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
