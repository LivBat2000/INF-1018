#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n)
{
    unsigned char c = 0;
    if (n >= 0 && n <= 8)
    {
        unsigned char a = x>>(8 - n);
        unsigned char b = x<<n;
        c = a|b;
    }
    else
    {
        printf("Valor inválido.\n");
    }
    return c;
}

int main(void)
{
    unsigned char x = 0x61;

    unsigned char a = rotate_left(x, 1);
    unsigned char b = rotate_left(x, 2);
    unsigned char c = rotate_left(x, 7);

    printf("De 1 bit: 0x%02x\n", a);
    printf("De 2 bits: 0x%02x\n", b);
    printf("De 7 bits: 0x%02x\n", c);

    return 0;
}