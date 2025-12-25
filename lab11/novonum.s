.data
Sf1: .string "numero: "
Sf2: .string "%d"

.text
.globl novonum
novonum:
    /* Registro de Ativação */
	pushq %rbp 
	movq %rsp, %rbp 
    subq $16, %rsp 

printf:
	movq  $Sf1, %rdi      #rdi = "numero: "
	call  printf   

scanf:
	movq $Sf2, %rdi       #rdi = "%d"
	leaq -4(%rbp), %rsi
    call scanf
    movl -4(%rbp), %eax   #eax = i 

fim:
	leave
	ret