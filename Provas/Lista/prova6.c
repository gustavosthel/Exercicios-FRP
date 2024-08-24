/*  (Lista Encadeada)

    QUESTÃO 06:
    Dada uma lista encadeada L, do tipo TLista,
    desenvolver uma função que exiba seus elementos na
    ordem inversa. Ou seja, se o ponteiro L estiver
    apontando para um nó que contém o valor 10, o 10
    será o último a ser exibido pela função.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int removerIntervalo(TLista *L, int a, int b);
int inserir(TLista *L, int numero);
void exibir(TLista L);

int main()
{
    // Criando uma lista vazia
    TLista lista = NULL;

    // Inserindo elementos para teste
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);

    exibir(lista);

    removerIntervalo(&lista, 1, 4);

    exibir(lista);

    return 0;
}

// Função para remover elementos entre posições a e b
int removerIntervalo(TLista *L, int a, int b)
{
    if (a < 1 || b < 1 || b < a)
    {
        return 0;
    }

    TLista anterior = NULL, atual = *L;
    TLista inicioRemocao = NULL, fimRemocao = NULL;
    int posicao = 1;

    // Encontrando a posição a
    while (atual && posicao < a)
    {
        anterior = atual;
        atual = atual->prox;
        posicao++;
    }

    // Verificando se a é uma posição válida
    if (!atual)
    {
        return 0;
    }

    inicioRemocao = atual;

    // Encontrando a posição b
    while (atual && posicao <= b)
    {
        fimRemocao = atual;
        atual = atual->prox;
        posicao++;
    }

    // Verificando se b é uma posição válida
    if (posicao <= b + 1 && !fimRemocao)
    {
        return 0;
    }

    // Removendo os elementos entre a e b
    if (anterior)
    {
        anterior->prox = atual;
    }
    else
    {
        *L = atual;
    }

    // Liberando a memória dos elementos removidos
    while (inicioRemocao != atual)
    {
        TLista temp = inicioRemocao;
        inicioRemocao = inicioRemocao->prox;
        free(temp);
    }

    return 1;
}

// Função para inserir um novo elemento no início da lista
int inserir(TLista *L, int numero)
{
    // Alocando memória para o novo elemento
    TLista aux = (TLista)malloc(sizeof(TNo));
    if (!aux)
    {
        return 0;
    }

    // Armazenando o valor no novo nó
    aux->valor = numero;

    // Fazendo o novo nó apontar para o antigo primeiro nó
    aux->prox = *L;

    // Atualizando o ponteiro para o novo primeiro nó
    *L = aux;

    return 1;
}

// Função para exibir os elementos da lista
void exibir(TLista L)
{
    TLista aux = L;

    // Verificando se a lista está vazia
    if (!L)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("Lista: ");
        while (aux)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}