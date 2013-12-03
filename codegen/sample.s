.text

_test: 
push %ebp
mov %esp, %ebp
#### visitFuncBlock
sub $12,%esp
#### VISIT Decl
#### Visit ID
#### ASSIGN
popl %eax
pushl $-2147483648
#### Visit ID
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
sub $4,%esp
#### VISIT Decl
#### Visit INT
pushl $50
#### Visit INT
pushl $100
####VISIT CALL
call _test
add  $0, %esp
popl %ebx
popl %ebx
pushl %eax
#### Visit ID
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
