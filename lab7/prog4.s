/*
#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/

.data
nums:  .int  65, -105, 111, 34
Sf:  .string "soma = %d\n"     /*string de formato para printf*/

.text
.globl  main
main:
/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

 movl  $0, %ebx  /* ebx = 0; */
 movl  $0, %r13d  /* r13d = 0; */
 movq $nums, %r12  /* r12 = &num; */

L1:
 cmpl  $4, %ebx
 je  L2          /* goto L2 */

 movl  %ebx, %eax
 imull $4, %eax
 movslq %eax, %rax
 addq  %r12, %rax
 movl  (%rax), %eax
 addl  %eax, %r13d        
 addl  $1, %ebx           
 jmp   L1

L2:
/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq  $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl  %r13d, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/


