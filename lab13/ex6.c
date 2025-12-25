#include <stdio.h>

typedef int (*funcp)(int);

int add(int x) {
    return x + 1;
}

int main(void) {
    unsigned char codigo[] = {
        0x55,                           // push   %rbp
        0x48, 0x89, 0xe5,               // mov    %rsp,%rbp
        0xe9, 0x00, 0x00, 0x00, 0x00,   // jmpq 9
        0xc9,                           // leaveq
        0xc3                            // retq
    };

    funcp f;
    int i, pos, desloc;

    // deslocamento CORRETO
    int x = (int)((char*)add - (char*)(codigo + 9));

    // escreve em little-endian
    for (i = 0, pos = 5, desloc = 0; i < 4; i++, pos++, desloc += 8)
        codigo[pos] = (x >> desloc) & 0xFF;

    f = (funcp)codigo;
    i = f(10);
    printf("O valor de i é %d\n", i);

    return 0;
}