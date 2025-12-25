#include <stdio.h>

typedef int (*funcp)(int);

int main() {
    unsigned char codigo[] = {
        0x55,                    // push %rbp
        0x48, 0x89, 0xe5,        // mov %rsp, %rbp
        0xff, 0xc7,              // inc %edi
        0x89, 0xf8,              // mov %edi, %eax
        0xc9,                    // leaveq
        0xc3                     // retq
    };

    funcp f = (funcp)codigo;
    int i = f(10);
    printf("Resultado = %d\n", i);

    return 0;
}