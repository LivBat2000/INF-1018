.text
.globl foo3
foo3:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
    movq %rbx, -8(%rbp)     //salva o valor de ebx da função chamadora

	movl $0, %ebx           //ebx(i) = 0 
	movq $0, %r10           //r10 = 0 
    cvtsi2sdq %r10, %xmm1   //converte de %r10 long para double

for:
	cmpl %esi, %ebx         //i < n?
	jge fim

	movsd %xmm1, -16(%rbp)  //guarda xmm1
	movq %rdi, -24(%rbp)    //guarda primeiro argumento
	movl %esi, -28(%rbp)    //guarda segundo argumento

	movsd (%rdi), %xmm0     //xmm0 = counteúdo de a
	call sin

	movsd -16(%rbp), %xmm1  //restaura r
	movq -24(%rbp), %rdi    //restaura primeiro argumento
	movl -28(%rbp), %esi    //restaura segundo argumento

	addsd %xmm0, %xmm1      //xmm1 += resultado de sin(*a)
	addq $8, %rdi           //rdi++
	incl %ebx               //i++ 
	jmp FOR

fim:
	movsd %xmm1, %xmm0  //xmm0 = r
    movq -8(%rbp), %rbx
	leave
	ret