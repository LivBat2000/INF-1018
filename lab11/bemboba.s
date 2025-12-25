.text
.globl bemboba
bemboba: 
	/* Registro de Ativação */ 
	pushq %rbp  
	movq %rsp, %rbp 
	subq $16, %rsp 

	movl $0, %r10d         # i = 0 
	leaq -16(%rbp), %r11   # a = local

for: 
	cmpl $4, %r10d         # i < 4? 
	jge loopf

	movl %edi, (%r11)      # *a = num 
	addq $4, %r11          #  a++ 

	incl %r10d             # i++ 
	jmp for 

loopf: 
	leaq -16(%rbp), %rdi     # rdi= local 
	movl $4, %esi            # esi = 4 
	call addl 

fim: 
	leave 
	ret