#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *esq;
    struct nodo *dir;
    
};

typedef struct nodo Nodo;

Nodo* create(int value){
    Nodo *n = malloc(sizeof(Nodo));
    n->valor = value;
    n->esq = NULL;
    n->dir = NULL;

    return n;
}

int main(){
    Nodo *nodo10 = create(10);
    Nodo *nodo8 = create(8);

    nodo8->dir = nodo10;
    

    return 0;
}