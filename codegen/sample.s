.text

PUBLIC _p
_p PROC
push ebp
mov esp, ebpsub esp, 0
#### PLUS
pushl $11
popl %ebx
pushl $11
pushl $11
popl %eax
mov ebp, esp 
pop ebp
ret
_p ENDP
END
