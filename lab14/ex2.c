#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BIT_SIG(x)   (((x) >> 31) & 1)
#define BIT_EXP(x)   (((x) >> 23) & 0xff)
#define BIT_FRAC(x)  ((x) & 0x7fffff)
#define BUILD_FLOAT(s,e,f) (((s)<<31) | ((e)<<23) | ((f) & 0x7fffff))

typedef union {
    float f;
    unsigned int i;
} U;

// 2^e <= n
unsigned maiorExpo2(int n)
{
    unsigned e = 0;
    while ((1u << e) <= (unsigned)n)
        e++;
    return e - 1;
}

float int2float(int i) {
    unsigned sinal, absval, exp2, mant, mant_raw;
    const unsigned bias = 127;
    U u;

    if (i == 0)
        return 0.0f;

    sinal  = (i < 0);
    absval = (unsigned)abs(i);

    exp2 = maiorExpo2(absval);
    mant_raw = absval - (1u << exp2);

    if (exp2 <= 23) {
        mant = mant_raw << (23 - exp2);
    } else {
        mant = mant_raw >> (exp2 - 23);
    }

    u.i = BUILD_FLOAT(sinal, exp2 + bias, mant);
    return u.f;
}

int main() {
   int i;

   printf("\n******** int2float ****************\n");
   i = 0;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 1;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -1;  
   printf(" %d -> %10.4f\n", i, int2float(i));
   i = 0x7fffffff;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -i;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 86118465;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   return 0;
}