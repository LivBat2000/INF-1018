/*
void foo (int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}
*/

/* Dicionário:
	Reg  Variável
	%rdi    a[]
	%esi    n
*/

.text
.globl foo
foo:
	/* Registro de Ativação */
	pushq %rbp    
	movq %rsp, %rbp
  subq $16, %rsp        
  movl %rbx, -8(%rbp)   

  movl $0, %ebx  
  movl $0, %ecx   

for:
    cmpl %esi, %ecx  # ecx == eci?
    jge fim

    movl $4, %edx  
    imull %ecx, %edx   # edx = 4*i 
    movslq %edx, %rdx  # estendo edx para 64 bits 
    movq %rdi, %r12    # r12 = rdi (a[]) 
    addq %rdx, %r12    
    addl (%r12), %ebx 

    cmpl $0, (%r12)    # a[i] == 0? 
    jne loopf
    movl %ebx, (%r12)   # a[i] = s 
    movl $0, %ebx      # s= 0
        
loopf:
    addl $1, %ecx  # i++
    jmp for

fim:
    movl -8(%rbp), %rbx 
    leave
    ret