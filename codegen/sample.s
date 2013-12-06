.text

.global Main
Main:
push %ebp
mov %esp, %ebp
sub $8,%esp
#### visitFuncBlock
#### VISIT Decl
#### Visit INT
pushl $0
#### ASSIGN
popl %eax
mov %eax, -4(%ebp)
#### VISIT FOR LOOP
#### Visit INT
pushl $15
#### ASSIGN
popl %eax
mov %eax, -8(%ebp)
jmp compare_expr0
func_body0:
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
#### MINUS
#### Visit ID
pushl -8(%ebp)
#### Visit INT
pushl $1
 popl %ebx
 popl %eax
 subl %ebx, %eax
 pushl %eax
#### ASSIGN
popl %eax
mov %eax, -8(%ebp)
compare_expr0:
#### NOTEQ !=
#### Visit ID
pushl -8(%ebp)
#### Visit INT
pushl $0
popl %ebx
popl %eax
cmp %ebx,%eax
jne func_body0
#### END FOR LOOP
#### Visit ID
pushl -4(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
