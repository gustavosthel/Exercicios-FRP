/* Lista de Exercícios X (Listas Encadeadas):

   QUESTÃO 09:
   Implementar uma função que, dada uma lista
   dinâmica do tipo TLista, verifique se os
   elementosda estrutura encontram-se ordenados
   de forma crescente ou não.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int testarOrdenacao(TLista L);
int inserir(TLista *L, int numero);
void exibir(TLista L);

int main()
{
    // declaração de variáveis
    TLista L1 = NULL;

    // inserindo elementos em L1
    inserir(&L1, 10);
    inserir(&L1, 11);
    inserir(&L1, 13);
    inserir(&L1, 18);

    exibir(L1);

    if (testarOrdenacao(L1))
    {
        printf("Estar ordenado cresentemente");
    }
    else
    {
        printf("NÃO esta ordenado cresentemente");
    }
}

int testarOrdenacao(TLista L)
{
    TLista aux1 = L;
    TLista aux2 = aux1->prox;

    if (aux1)
    {
        while (aux2)
        {

            if (aux1->valor < aux2->valor)
            {
                return 0;
            }

            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
    }

    return 1;
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