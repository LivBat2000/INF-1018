.text
.globl foo2
foo2:
	pushq %rbp 
	movq %rsp, %rbp
	subq $16, %rsp 

    cvtss2sd %xmm0, %xmm0   //converte a para double
	cvtss2sd %xmm1, %xmm1   //converte b para double
	movsd %xmm1, -8(%rbp)   //guarda b
	call sin  
	movsd %xmm0, -16(%rbp)  //guarda resultado de sin(a)
	movsd -8(%rbp), %xmm0   //xmm0 = b
	call cos 
	addsd -16(%rbp), %xmm0   //xmm0(cosseno de b) + seno de a

	leave
	ret