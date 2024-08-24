/* Lista de Exercícios IX (Listas Encadeadas):

    QUESTÃO 06:
    Desenvolver uma função que, dada uma lista encadeada L,
    remova as repetições de L de forma que a lista apresente,
    ao final, apenas uma ocorrência de cada elemento existente
    na lista originalmente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

void removerRepetidos(TLista *L1);
int inserir(TLista *L, int numero);
void exibir(TLista L);

int main()
{
    TLista L1 = NULL;
    inserir(&L1, 1);
    inserir(&L1, 1);
    inserir(&L1, 2);
    inserir(&L1, 3);
    inserir(&L1, 1);

    printf("Lista Original:\n");
    exibir(L1);

    removerRepetidos(&L1); // Remover repetições

    printf("\nLista sem Repetições:\n");
    exibir(L1);

    return 0;
}

void removerRepetidos(TLista *L1)
{
    TLista atual = *L1;
    TLista anterior, aux;

    while (atual)
    {
        anterior = atual;
        aux = atual->prox;

        while (aux)
        {
            if (atual->valor == aux->valor)
            {
                anterior->prox = aux->prox; // Remove o nó repetido
                free(aux);                  // Libera a memória do nó removido
                aux = anterior->prox;       // Atualiza o ponteiro aux para continuar a verificação
            }
            else
            {
                anterior = aux;
                aux = aux->prox;
            }
        }

        atual = atual->prox;
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