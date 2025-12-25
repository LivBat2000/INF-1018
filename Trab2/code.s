.text
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp

    leave
    ret

    movl    %edi, -24(%rbp)

    movl    -24(%rbp), %r10d
    movl    -24(%rbp), %r11d

    addl    %r11d, %r10d
    subl    %r11d, %r10d
    imul    %r11d, %r10d

    movl    %r10d, -20(%rbp)
    movl    %r10d, -16(%rbp)
    movl    %r10d, -12(%rbp)
    movl    %r10d, -8(%rbp)
    movl    %r10d, -4(%rbp)