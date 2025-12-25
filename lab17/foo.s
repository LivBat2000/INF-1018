.text
.globl foo
foo:
	push %rbp
	movq %rsp, %rbp

    movl $0, %r10d               //r10d = 0
    subl %edi, %r10d             //r10d = r10d - edi
    cvtsi2sd %r10d, %xmm1        //converte -b para double */
    mulsd %xmm1, %xmm0           //xmm0 = a * (-b)

	leave
	ret