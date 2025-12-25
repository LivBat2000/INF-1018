.text
.globl foo1
foo1:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp

    cvtss2sd %xmm0, %xmm0   //converto a para double */
	cvtss2sd %xmm1, %xmm1   //converto b para double */
	movsd %xmm1, -8(%rbp)   //guarda b
	call sin              
	addsd -8(%rbp), %xmm0   //xmm0(seno de a) + xmm1(b)

	cvtsd2ss %xmm0, %xmm0   //converto retorno de double para float
	leave
	ret