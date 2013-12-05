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
#### GREATER Than
 pushl $0
#### Visit INT
pushl $5
#### ASSIGN
popl %eax
mov %eax, -4(%ebp)
#### IFNOELSE
popl %eax
movl $0, %ebx
cmp %eax, %ebx
je skip_if_1
#### Visit INT
pushl $5
#### ASSIGN
popl %eax
mov %eax, -4(%ebp)
skip_if_1:
#### PLUS
#### Visit ID
pushl -4(%ebp)
#### Visit INT
pushl $1
popl %ebx
popl %eax
addl %ebx, %eax
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
