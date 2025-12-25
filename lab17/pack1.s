Dicionário
-8(%rbp)  → acc (double)
-16(%rbp) → px (struct X1*)
-20(%rbp) → n (int)
-24(%rbp) → i (int)

.text
.globl pack1
pack1:
    push    %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp

    movq    %rdi, -16(%rbp)      //px
    movl    %esi, -20(%rbp)      //n

    //acc = 0.0
    xorpd   %xmm0, %xmm0
    movsd   %xmm0, -8(%rbp)
    movl    $0, -24(%rbp)       //i = 0

for:
    movl    -24(%rbp), %eax      //eax = i
    cmpl    -20(%rbp), %eax      /qi >= n?
    jge     fim

    # calcular endereço de px[i]
    movq    -16(%rbp), %rdi      //rdi = px
    movl    -24(%rbp), %eax      //eax = i
    imull   $8, %eax             //eax = i*8 (sizeof(struct X1)=8)
    addq    %rax, %rdi           //rdi = px + i*8

    movl    (%rdi), %esi         //esi = px[i].vi (segundo argumento de foo)
    cvtss2sd 4(%rdi), %xmm0      //xmm0 = px[i].vf (primeiro argumento de foo)
    call    foo

    //acc += resultado de foo (em xmm0)
    addsd   -8(%rbp), %xmm0
    movsd   %xmm0, -8(%rbp)
    incl    -24(%rbp)           //i++
    jmp   for  

fim:
    movsd   -8(%rbp), %xmm0
    leave
    ret