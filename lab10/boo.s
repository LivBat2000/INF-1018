/*
Dicionário
%rdi        px  
%esi        n
%edx        val
*/

.text
.globl boo
boo:
    /* Registro de Ativação */
	pushq %rbp 
	movq %rsp, %rbp
    subq $16, %rsp   

while:    
    cmpl $0, %esi    #esi (n) == 0?
    je fim

    movq %rdi, -8(%rbp)
    movl %esi, -12(%rbp)
    movl %edx, -16(%rbp)

    movl %edx, %esi 
    call f       

    movq -8(%rbp), %rdi
    movl -12(%rbp), %esi
    movl -16(%rbp), %edx

    movl %eax, 4(%rdi) 

    addq $8, %rdi     # px++   
    decl %esi         # n--
    jmp while

fim:
    leave
    ret