/* Lista de Exercícios IX (Listas Encadeadas):

    QUESTÃO 05:
    Considere a existência de uma lista L, do
    tipo TLista. Implementar uma função que crie
    uma nova lista com os mesmos elementos de L,
    porém sem repetição.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int clonar(TLista L1, TLista *L2);
int inserir(TLista *L, int numero);
void exibir(TLista L);

int main()
{
    TLista L1 = NULL, L2 = NULL;
    inserir(&L1, 1);
    inserir(&L1, 2);
    inserir(&L1, 2);
    inserir(&L1, 3);
    inserir(&L1, 1);

    printf("Lista Original:\n");
    exibir(L1);

    if (clonar(L1, &L2))
    {
        printf("\nLista Clonada sem Repetições:\n");
        exibir(L2);
    }
    else
    {
        printf("\nLista nao foi clonada!");
    }
}

int clonar(TLista L1, TLista *L2)
{
    TLista aux = L1, novo, aux2 = *L2, ultimo = NULL;
    int repetido = 0;

    if (!L1)
    {
        return 0;
    }
    else
    {
        while (aux)
        {
            repetido = 0;
            aux2 = *L2;

            while (aux2)
            {
                if (aux->valor == aux2->valor)
                {
                    repetido = 1;
                }
                aux2 = aux2->prox;
            }

            if (repetido == 0)
            {

                novo = (TLista)malloc(sizeof(TNo));

                if (!novo)
                {
                    return 0;
                }
                else
                {
                    novo->valor = aux->valor;
                    novo->prox = NULL;

                    if (!*L2)
                    {
                        *L2 = novo;
                    }
                    else
                    {
                        ultimo->prox = novo;
                    }
                    ultimo = novo;
                }
            }
            aux = aux->prox;
        }
        return 1;
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