.text

_test: 
push %ebp
mov %esp, %ebp
arg: a
arg: b
#### visitFuncBlock
sub $12,%esp
#### VISIT Decl
#### Visit INT
pushl $5
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
####VISIT CALL
#### Visit INT
pushl $50
#### Visit INT
pushl $100
pushl $100
pushl $50
call _test
pushl %eax
#### Visit ID
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
