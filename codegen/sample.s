.text

.globl Main
Main:
push %ebp
mov %esp, %ebp
sub $8,%esp
#### visitFuncBlock
#### Visit INT
pushl $5
#### ASSIGN
popl %eax
mov %eax, -8(%ebp)
#### VISIT FOR LOOP
#### Visit INT
pushl $0
#### ASSIGN
popl %eax
mov %eax, -4(%ebp)
jmp compare_expr0
func_body0:
#### PLUS
#### Visit ID
pushl -8(%ebp)
#### Visit INT
pushl $1
popl %ebx
popl %eax
addl %ebx, %eax
pushl %eax
#### ASSIGN
popl %eax
mov %eax, -8(%ebp)
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
compare_expr0:
#### Visit ID
pushl -4(%ebp)
#### Visit INT
pushl $10
popl %ebx
popl %eax
cmp %ebx,%eax
jl equal1
pushl $0
jmp end1
equal1:
pushl $1
end1:
pop %ebx
mov $1, %eax
cmp %ebx,%eax
je func_body0
#### END FOR LOOP
#### Visit ID
pushl -8(%ebp)
#### RETURN
popl %eax
mov %ebp, %esp 
pop %ebp
	ret
