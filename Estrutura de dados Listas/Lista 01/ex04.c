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

void imprimir(Nodo *n){
    if(n->esq == NULL){
        printf("\nvazio");
    }else{
        printf("%d",n->valor);
    }
    
}

int main(){
    Nodo *nodo5 = create(5);
    Nodo *nodo4 = create(4);
    Nodo *nodo8 = create(8);

    nodo5->esq = nodo4;

    imprimir(nodo8);

    return 0;
}