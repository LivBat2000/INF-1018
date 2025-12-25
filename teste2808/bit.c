#include <stdio.h>

int main(void)
{
    unsigned char a, b, c;

    a = 0x5a;
    b = 0xa5;
    c = a && b;

    printf("a = 0x%02x, b = 0x%02x, c = 0x%02x\n", a, b, c);

    return 0;
}