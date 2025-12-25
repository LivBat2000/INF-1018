/*
int add (int a, int b, int c) {
  return a+b+c;
}
*/

.text
.globl add
add:
	pushq %rbp
	movq %rsp, %rbp

L1:
	movl %edi, %eax   /* int a */
	addl %esi, %eax   /* int b + a */
	addl %edx, %eax   /* int c + b + a */

L2:
	leave
    ret