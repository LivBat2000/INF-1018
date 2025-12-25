#include <stdio.h>

unsigned char switch_byte(unsigned char x)
{
    unsigned char a = x>>4;
    unsigned char b = x<<4;
    unsigned char c = a|b;
    return c;
}

int main(void)
{
    unsigned char x = 0xAB;
    unsigned char a = switch_byte(x);
    printf("0x%02x\n", a);
    return 0;
}