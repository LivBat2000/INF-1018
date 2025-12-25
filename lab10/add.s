/*
Dicionário
%rdi      x 
%esi      a               
*/

.text
.globl add
add:
	/* Registro de Ativação */
	pushq %rbp
	movq %rsp, %rbp    

	movl $0, %esi    #a = 0

for:
	cmpq $0, %rdi     #x == NULL? 
	je fim
	addl (%rdi), %esi  #a = a+(*x)
    addq $8, %rdi
    movq (%rdi), %rdi
	jmp for

fim:
	movl %esi, %eax 
	leave
    ret