/*
Dicionário
%rdi       x              
*/

.text
.globl add2
add2:
	/* Registro de Ativação */
	pushq %rbp 
	movq %rsp, %rbp    
    subq $16, %rsp
    movq %rbx, -8(%rbp)

if:
    cmpq $0, %rdi    #x == NULL?
    jne else

    movl $0, %eax    #eax = 0 
    jmp fim

else:
    movl (%rdi), %ebx     #ebx = x->val
    addq $8, %rdi
    movq (%rdi), %rdi
    call add2 
    addl %ebx, %eax    #eax = eax

fim:
    movq -8(%rbp), %rbx
    leave
    ret