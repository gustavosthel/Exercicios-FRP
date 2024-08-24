/* Lista de Exercícios X (Listas Encadeadas):

   QUESTÃO 06:
   Desenvolver uma função que, dada uma lista L1, crie
   uma nova lista L2, cópia de L1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int copiarLista(TLista L1, TLista *L2);
int inserir(TLista *L, int numero);
void exibir(TLista L);

int main()
{

    // declaração de variáveis
    TLista L1 = NULL, L2 = NULL;

    // inserindo elementos em L1
    inserir(&L1, 10);
    inserir(&L1, 4);
    inserir(&L1, 13);
    inserir(&L1, 7);

    // inserindo elementos em L2
    inserir(&L2, 8);

    exibir(L1);
    exibir(L2);

    if (copiarLista(L1, &L2) == 1)
    {
        printf("Lista 1 copiada para a Lista 2\n\n");
    }
    else
    {
        printf("Não existe elementos para ser copiados!\n\n");
    }

    exibir(L2);
}

int copiarLista(TLista L1, TLista *L2)
{
    TLista aux = L1;
    TLista novo;

    if (!aux)
    {
        return 0;
    }
    else
    {
        while (aux)
        {

            novo = (TLista)malloc(sizeof(TNo));

            novo->valor = aux->valor;

            novo->prox = *L2;

            *L2 = novo;

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
