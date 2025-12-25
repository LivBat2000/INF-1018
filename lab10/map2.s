.text
.globl map2
map2:
    	/* Registro de Ativação */
	pushq %rbp 
	movq %rsp, %rbp 
    subq $32, %rsp
    movq %rbx, -8(%rbp)

    movl $0, %ebx     # i = 0

for:
    cmpl %edx, %ebx  # i < n?
    jge fim

    # outro[i]
    movslq %ebx, %r10
    imulq $4, %r10       # r10 = 4*i
    addq %rsi, %r10 

    # um[i]
    movslq %ebx, %r11
    imulq $4, %r11      # r11 = 4*i
    addq %rdi, %r11 

    movq %rdi, -16(%rbp)
    movq %rsi, -24(%rbp)
    movl %edx, -28(%rbp)
       
    movq (%r11), %edi
    call f

    movq -16(%rbp), %rdi
    movq -24(%rbp), %rsi
    movl -28(%rbp), %edx

    movl %eax, (%r10)
    incl %ebx         # i++
    jmp for

fim:
    movq -8(%rbp), %rbx
    leave
    ret