#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tp_produto{
	int codigo;
	char nome[100];
	struct tp_produto *prox;
};

typedef struct tp_produto Produto;

//== ponteiros para controlar as extremidades da fila
Produto *inicio = NULL;
Produto *fim = NULL;

//== Inserção (Enqueue/enfileirar) que entra pelo fim da fila
void inserir(int cod, char n[] ){
	Produto *produto = (Produto*)malloc(sizeof(Produto));
	produto->codigo = cod;
	strcpy(produto->nome, n);
	produto->prox = NULL;  //== o ultimo elemento sempre aponta para nulo no prox
	if(inicio==NULL){
		inicio = produto;  //==se for o primeiro, e inicio e fim ao mesmo tempo
	}else{
		fim->prox = produto;
	}
	fim = produto; //== atualiza o fim com o novo elemento
	printf("Inserido na fila %s\n ", n);	
}

//== Remoção (Dequeue) sai pelo inicio
void remover(){
	if(inicio==NULL){
		printf("Fila Vazia!\n");
		return;
	}
	Produto *aux = inicio; //==Guarda o inicio para liberar depois
	printf("Removendo da fila %s\n", aux->nome);
	inicio = inicio->prox; //== o inicio agora e o segundo da fila
	
	if(inicio==NULL){
		fim = NULL; //== se a fila esvaziou, o fim tb fica nulo
	}
	free(aux); //== deleta o elemento que saiu	
}

void listar(){
	Produto *aux = inicio;
	printf("\n====== Fila de produtos ====== \n");
	while(aux!=NULL){
		printf("Código: %i Nome: %s\n ", aux->codigo, aux->nome);
		aux = aux->prox;		
	}
	system("pause");	
}

int main(){
	inserir(1, "sofa");
	inserir(2, "mesa");
	inserir(3, "armario");
	printf("\nListando produtos\n");
	listar();
	printf("\nEstado: O primeiro a sair sera o sofa (FIFO) \n");
	remover(); //== remove o sofa
	printf("\nListando produtos\n");
	listar();
	remover(); //== remove a mesa	
	printf("\nListando produtos\n");
	listar();
	return 0;
}











