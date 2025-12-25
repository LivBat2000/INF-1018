Dicionário
%edi         x
%eax        x+1  

.text
.globl foo4
foo4:
	pushq %rbp
    movq %rsp, %rbp

    call add

	leave
	ret