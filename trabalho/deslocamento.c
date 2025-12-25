#include "bigint.h"
#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

/*Deslocamentos*/

/*res = a << n*/
void big_shl(BigInt res, BigInt a, int n)
{
    //caso nao precise mover (n de 0 bits)
    if (n == 0)
    {
        for (int i = 0; i < NUM_BITS/8; i++)
        {
            res[i] = a[i]; //copia byte a byte
        }
        return;
    }

    //caso n seja maior ou igual ao numero de bits
    if (n >= NUM_BITS)
    {
        big_val(res, 0); 
        return;
    }

    //buffer temporario
    unsigned char temp[NUM_BITS/8];

    //preencher o buffer com 0s
    for (int i = 0; i < NUM_BITS/8; i++)
    {
        temp[i] = 0;
    }

    //calcula quantos bytes e bits precisam ser deslocados
    int bycheio = n / 8;
    int bresto = n % 8;


    //desloca bytes completos da direita pra esquerda
    for (int i = NUM_BITS/8-1; i >= bycheio; i--)
    {
        temp[i] = a[i - bycheio];
    }

    //desloca bits restantes dentro dos bytes
    if (bresto > 0)
    {
        for (int i = NUM_BITS/8-1; i >= 0; i--)
        {
            //desloca os bits do byte atual pra esquerda
            unsigned int valor = temp[i] << bresto;

            //caso nao esteja no primeiro byte, pega os bits que foram para fora do byte anterior
            if (i > 0)
            {
                unsigned int antByteBits = temp[i-1] >> (8 - bresto);
                valor += antByteBits;
            }
            //pega os 8 bits menos significativos no byte e os armazena
            temp[i] = valor & 0xFF;
        }
    }
    //copia o que esta no buffer temp para o resultado
    for (int i = 0; i < NUM_BITS/8; i++)
    {
        res[i] = temp[i];
    }
}

/*res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n)
{
    //caso nao precise mover (n de 0 bits)
    if (n == 0)
    {
        for (int i = 0; i < NUM_BITS/8; i++)
        {
            res[i] = a[i]; //copia byte a byte
        }
        return;
    }

    //caso n seja maior ou igual ao número de bits
    if (n >= NUM_BITS)
    {
        big_val(res, 0); 
        return;
    }

    //buffer temporario
    unsigned char temp[NUM_BITS/8];

    //preencher o buffer com 0s
    for (int i = 0; i < NUM_BITS/8; i++)
    {
        temp[i] = 0;
    }

    //calcula quantos bytes e bits precisam ser deslocados
    int bycheio = n / 8;
    int bresto = n % 8;

    //desloca bytes completos da esquerda pra direita
    for (int i = 0; i < NUM_BITS/8 - bycheio; i++)
    {
        temp[i] = a[i + bycheio];
    }

    //desloca bits restantes dentro dos bytes
    if (bresto > 0)
    {
        for (int i = 0; i < NUM_BITS/8; i++)
        {
            //desloca os bits do byte atual pra direita
            unsigned int valor = temp[i] >> bresto;

            //caso nao esteja no ultimo byte, pega os bits que foram para fora do proximo byte a direita
            if (i < NUM_BITS/8 -1)
            {
                unsigned int proxByteBits = temp[i+1] << (8 - bresto);
                valor += proxByteBits;
            }
            //pega os 8 bits menos significativos no byte e os armazena
            temp[i] = valor & 0xFF;
        }
    }
    //copia o que esta no buffer temp para o resultado
    for (int i = 0; i < NUM_BITS/8; i++)
    {
        res[i] = temp[i];
    }
}

/*res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n)
{
    //caso nao precise mover (n de 0 bits)
    if (n == 0)
    {
        for (int i = 0; i < NUM_BITS/8; i++)
        {
            res[i] = a[i]; //copia byte a byte
        }
        return;
    }

    //caso n seja maior ou igual ao número de bits, sera todo positivo ou negativo
    if (n >= NUM_BITS)
    {
        //caso o bit mais significativo for 1 (negativo)
        if (a[NUM_BITS/8 - 1] & 0x80)
        {
            //preenche tudo com 1s
            for (int i = 0; i < NUM_BITS/8; i++)
            {
                res[i] = 0xFF;
            }
        }
        //caso o bit mais significativo for 0 (positivo)
        else
        {
            //preenche tudo com 0s
           for (int i = 0; i < NUM_BITS/8; i++)
            {
                res[i] = 0x00;
            }
        }
        return;
    }

    //shift pra direita logico
    big_shr(res, a, n);

    //se o numero e negativo, vai fazer a extensao do sinal
    if (a[NUM_BITS/8 - 1] & 0x80)
    {
        //calcula quantos bytes e bits precisam ser preenchidos com 1s
        int bycheio = n / 8;
        int bresto = n % 8;

        //preence os bytes mais significativos com 1s
        for (int i = NUM_BITS/8 - 1; i >= NUM_BITS/8 - bycheio; i--)
        {
            res[i] = 0xFF;
        }

        //preenche os bits restantes com 1s
        if (bresto > 0 && bycheio < NUM_BITS/8)
        {
            int j = NUM_BITS/8 - 1 - bycheio; //ajusta a posicao
            unsigned char masc = (0xFF << (8 - bresto)) & 0xFF;
            res[j] |= masc; //seta os bits mais significativos
        }
    }
}