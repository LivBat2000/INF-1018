.text
.globl foo
foo:
	pushq %rbp
	movq %rsp, %rbp

	cvtss2sd %xmm1, %xmm1   // converte b de float para double
	movsd %xmm0, %xmm2      // guarda double a em xmm2
	addsd %xmm1, %xmm0      // xmm0 = a+b
	subsd %xmm1, %xmm2      // xmm2 = xmm2(a)-b
    mulsd %xmm2, %xmm0      // xmmo(a+b) * xmm2(a-b)

	cvtsd2ss %xmm0, %xmm0   //converte retorno de double pra float
	leave
	ret