#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// define o tipo da struct aluno (nó da fila)
struct tp_aluno{
    int codigo;
    char nome[100];
    struct tp_aluno *prox;
};

// cria um apelido para struct tp_aluno
typedef struct tp_aluno Aluno;

// ponteiros que controlam o início e o fim da fila
Aluno *inicio = NULL;
Aluno *fim = NULL;

// Inserção (Enqueue): sempre entra no fim da fila
void inserir(int cod, char nome[]){
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    if(aluno == NULL){
        printf("Erro: sem memoria para inserir aluno.\n");
        return;
    }

    aluno->codigo = cod;
    strcpy(aluno->nome, nome);
    aluno->prox = NULL;

    // se a fila estiver vazia, o novo aluno é início e fim
    if(inicio==NULL){
        inicio = aluno;
    }else{
        // se já tiver elementos, encadeia no final atual
        fim->prox = aluno;
    }

    // atualiza o fim para o novo nó
    fim = aluno;
    printf("Inserido na fila: %s\n", nome);

}

// Remoção (Dequeue): sempre sai pelo início da fila
void remover(){
    if(inicio == NULL){
        printf("Fila vazia! Nao ha aluno para remover.\n");
        return;
    }

    // guarda o início atual para liberar depois
    Aluno *aux = inicio;
    printf("Removendo: %s (codigo %d)\n", aux->nome, aux->codigo);

    // avança o início para o próximo nó
    inicio = inicio->prox;

    // se a fila ficou vazia, o fim também deve virar NULL
    if(inicio == NULL){
        fim = NULL;
    }

    // libera a memória do nó removido
    free(aux);
}

// Listagem dos alunos da fila do início para o fim
void listar(){
    Aluno *aux = inicio;

    if(aux == NULL){
        printf("\nFila vazia!\n");
        return;
    }

    printf("\n===== Fila de Alunos =====\n");
    while(aux != NULL){
        printf("Codigo: %d | Nome: %s\n", aux->codigo, aux->nome);
        aux = aux->prox;
    }
}

// Libera toda memória restante da fila (boa prática antes de encerrar)
void limpar_fila(){
    while(inicio != NULL){
        remover();
    }
    printf("Fila limpa com sucesso.\n");

}



int main()
{
    inserir(1, "Ana");
    inserir(2, "Bruno");
    inserir(3, "Carla");

    listar();

    printf("\nOrdem FIFO: primeiro a sair e Ana.\n");
    remover();
    listar();

    remover();
    listar();

    remover();
    listar();

    limpar_fila();

    return 0;
}












