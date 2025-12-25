Dicionário
%rdi           *px 
%xmm0          acc 

.text
.globl pack
pack:
	push %rbp
	movq %rsp, %rbp
	subq $16, %rsp

	movq $0, %r10
    cvtsi2sdq %r10, %xmm0    //acc = 0

while:
	cmpq $0, %rdi            //px != NULL?
	je fim

	movq %rdi, -8(%rbp)      //salvando o rdi
	movsd %xmm0, -16(%rbp)   //salvando o xmm0

	movsd 8(%rdi), %xmm0     //xmm0 recebe px->vd
    movl (%rdi), %edi        //edi recebe px->vi
	call foo

	addsd -16(%rbp), %xmm0   //xmm0 = xmm0 + acc
	movq -8(%rbp), %rdi      //restaurando edi

	movq 16(%rdi), %rdi      //px = px->next
	jmp while

fim:
	leave
	ret