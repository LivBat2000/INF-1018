#include <stdio.h>

void foo(int a[], int n);

int main()
{
    int a[] = {3, 4, 0, 2, 9};
    foo(a, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}