/*  (Lista Encadeada)

    QUESTÃO 01:
    Implementar uma função que, dado um ponteiro do
    tipo TLista, determine o menor valor desse nó até o
    final da lista. Em seguida, trocar os valores destes nós
    (o apontado pelo ponteiro dado e o que armazena o
    menor elemento encontrado), caso os elementos
    armazenados por eles sejam distintos.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int trocarMenoValor(TLista *L);
int inserir(TLista *L, int numero);
void exibir(TLista L);

int main()
{
    TLista L = NULL;
    inserir(&L, 8);
    inserir(&L, 2);
    inserir(&L, 2);
    inserir(&L, 3);
    inserir(&L, 8);

    exibir(L);

    trocarMenoValor(&L);

    exibir(L);

    return 0;
}

int trocarMenoValor(TLista *L)
{
    if (!*L)
    {
        return 0;
    }
    else
    {
        TLista menoNo = *L;
        TLista aux1 = (*L)->prox;

        while (aux1)
        {
            if (aux1->valor < menoNo->valor)
            {
                menoNo = aux1;
            }
            aux1 = aux1->prox;
        }

        if (menoNo->valor != (*L)->valor)
        {
            int temp = (*L)->valor;
            (*L)->valor = menoNo->valor;
            menoNo->valor = temp;
        }
    }
}

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