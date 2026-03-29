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
    

    return 0;
}