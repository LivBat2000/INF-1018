/*
int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/

.text
.globl fat
fat:
	pushq %rbp
	movq  %rsp, %rbp
	subq  $16, %rsp

L1:
	cmpl  $0, %edi       /* n==0? */
	jne   L2

	movl  $1, %eax
	jmp L3

L2:
	movl %edi, -4(%rbp)
	sub $1, %edi  /* edi = edi-1 */
	call fat	
	movl -4(%rbp), %edi
	imull %edi, %eax

L3:
	leave
	ret