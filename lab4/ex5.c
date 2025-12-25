#include <stdio.h>
#include <stdlib.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main(void)
{
    signed char sc = -1;
    unsigned int ui = sc;

    printf("signed char: %d\n", sc);
    printf("unsigned int: %u\n", ui);

    printf("Dump ui: \n");
    dump(&ui, sizeof(ui));

    return 0;
}