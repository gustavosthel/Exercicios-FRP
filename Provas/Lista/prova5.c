/*  (Lista Encadeada)

    QUESTÃO 05:
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

void exibirInvertido(TLista L);
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

    // Exibindo os elementos da lista na ordem inversa sem usar recursão
    exibirInvertido(lista);

    return 0;
}

// Função para exibir os elementos da lista na ordem inversa sem recursão
void exibirInvertido(TLista L)
{
    TLista pilha = NULL; // Pilha para armazenar os nós da lista
    TLista aux = L;      // Auxiliar para percorrer a lista original

    // Empilhando os elementos da lista na pilha
    while (aux != NULL)
    {
        TLista novoNode = (TLista)malloc(sizeof(TLista));
        if (novoNode == NULL)
        {
            printf("Erro ao alocar memória para novo nó.\n");
            return;
        }
        novoNode->valor = aux->valor;
        novoNode->prox = pilha;
        pilha = novoNode;
        aux = aux->prox;
    }

    // Desempilhando e exibindo os elementos da pilha (ordem inversa)
    printf("Lista invertida: ");
    while (pilha != NULL)
    {
        printf("%d ", pilha->valor);
        TLista temp = pilha;
        pilha = pilha->prox;
        free(temp);
    }
    printf("\n");
}

// Função para inserir um novo elemento no início da lista
int inserir(TLista *L, int numero)
{
    // declaração de variáveis
    TLista aux;

    // Passo 1: alocar memória para o novo elemento
    aux = (TLista)malloc(sizeof(TNo)); // malloc - memory allocation

    // verificando se houve erro na alocação
    if (!aux)
    {
        return 0;
    }
    else
    {
        // Passo 2: armazenando 'numero' na posição recém-alocada
        aux->valor = numero;

        // Passo 3: fazer o novo nó apontar para o "antigo primeiro nó"
        aux->prox = *L;

        // Passo 4: fazer com que *L aponte para o novo Nó
        *L = aux;

        return 1;
    }
}

void exibir(TLista L)
{
    // declaração de variáveis
    TLista aux = L;

    // verificando se a lista está vazia
    if (!L)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("Lista: ");

        // while (aux != NULL)
        while (aux)
        {
            printf("%d ", aux->valor);
            // ou:    printf ("%d ", (*aux).valor);

            aux = aux->prox;
        }
        printf("\n");
    }
}