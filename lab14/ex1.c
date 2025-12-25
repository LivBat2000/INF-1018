#include <stdio.h>
#define MAKE_FLOAT(s,e,f) (((s)&1)<<31 | (((e)&0xff)<<23) | ((f)&0x7fffff))
#define SIG(x)   (((x)>>31) & 1)
#define EXP(x)   (((x)>>23) & 0xff)
#define FRAC(x)  ((x) & 0x7fffff)

typedef union {
    float f;
    unsigned int i;
} U;

// Retorna f * 2
float float2(float f) {
    unsigned sig, exp, frac;
    U u;

    u.f = f;
    sig  = SIG(u.i);
    exp  = EXP(u.i);
    frac = FRAC(u.i);

    printf("Sinal = %u,  Exp = %02X,  Frac = %06X\n", sig, exp, frac);

    exp++;   // desloca a potência em +1 → multiplica por 2

    u.i = MAKE_FLOAT(sig, exp, frac);
    return u.f;
}

// Retorna f / 2 
float metade_float(float f) {
    unsigned sig, exp, frac;
    U u;

    u.f = f;
    sig  = SIG(u.i);
    exp  = EXP(u.i);
    frac = FRAC(u.i);

    printf("Sinal = %u,  Exp = %02X,  Frac = %06X\n", sig, exp, frac);

    exp--;   // desloca a potência em -1 → divide por 2

    u.i = MAKE_FLOAT(sig, exp, frac);
    return u.f;
}

int main(void) {
    float valor = 15213.0f;

    printf("Antes = %f\n", valor);

    valor = metade_float(valor);
    printf("Depois = %f\n", valor);

    return 0;
}