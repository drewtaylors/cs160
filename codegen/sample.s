.text

.global Main
Main:
push %ebp
mov %esp, %ebp
#### visitFuncBlock
#### VISIT Decl
#### Visit INT
pushl $0
#### ASSIGN
popl %eax
mov %eax, -4(%ebp)
#### IF WITH ELSE
#### Visit INT
pushl $7
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
