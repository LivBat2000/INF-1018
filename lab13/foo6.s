Dicionário
%edi         x
%eax        x+1  

.text
.globl foo6
foo6:
	pushq %rbp
    movq %rsp, %rbp

    jmp add

	leave
	ret