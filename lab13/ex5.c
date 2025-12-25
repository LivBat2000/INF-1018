#include <stdio.h>

typedef int (*funcp)(int);

int add(int x) {
    return x + 1;
}

int main(void) {
    funcp f;
    int i, pos, desloc;

    static unsigned char codigo[] = {
        0x55,                           // push   %rbp
        0x48, 0x89, 0xe5,               // mov    %rsp,%rbp
        0xe8, 0x00, 0x00, 0x00, 0x00,   // callq 9
        0xc9,                           // leaveq
        0xc3                            // retq
    };

    int x = (int)((char*)add - (char*)(codigo + 9));

    for (i = 0, pos = 5, desloc = 0; i < 4; i++, pos++, desloc += 8) {
        codigo[pos] = (x >> desloc) & 0xFF;
    }

    f = (funcp)codigo;
    int r = f(10);

    printf("Resultado: %d\n", r);
    return 0;
}