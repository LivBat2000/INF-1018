#include <stdio.h>
#include <stdlib.h>

struct nodo 
{
    int chave;
    int altura;
    struct nodo * esq;          
    struct nodo * dir;
};
Typedef struct nodo Nodo;

Nodo* criarNo(int chave)
{
    Nodo* no = (Nodo*)malloc(sizeof(Nodo));
    no->chave =  chave;
    no->altura = 0;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

Nodo* insere(Nodo* r, int chave)
{
    if (r == NULL)
    {
        return criarNo(chave);
    }
    else if (chave < r->chave)
    {
        r->esq = insere(r->esq, chave);
    }
    else
    {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

int calculaAltura(Nodo* r)
{
    if (r == NULL)
    {
        exit(1);
    }

    int alturaEsq = calculaAltura(r->esq);
    int alturaDir = calculaAltura(r->dir);

    r->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;

    return r->altura;
}

