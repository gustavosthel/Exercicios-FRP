/* Lista de Exercícios IX (Listas Encadeadas):

    QUESTÃO 01:
    Desenvolver uma função que remova todos os elementos
    de uma pilha P do tipo TLista e retorne aquantidade
    de elementos que existiam em P.

    Nota: as regras de manipulação de uma pilha clássica
    devem ser respeitadas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int removerPilha(TLista *P);
int empilhar(TLista *P, int numero);

int main()
{
    TLista P = NULL;
    int resul;

    empilhar(&P, 9);
    empilhar(&P, 18);
    empilhar(&P, 7);

    resul = removerPilha(&P);

    if (resul == 0)
    {
        printf("A pilha esta fazia!");
    }
    else
    {
        printf("Foram removidos %d elementos da pilha", resul);
    }
}

int removerPilha(TLista *P)
{
    TLista aux = *P;
    int cont = 0;

    if (*P)
    {
        while (aux)
        {
            *P = aux->prox;
            free(aux);
            aux = *P;
            cont++;
        }
        return cont;
    }
    else
    {
        return 0;
    }
}

int empilhar(TLista *P, int numero)
{
    // declaração de variáveis
    TLista novo;

    // Passo 1: alocar memória para o novo elemento
    novo = (TLista)malloc(sizeof(TNo)); // malloc - memory allocation

    // verificando se houve erro na alocação
    if (!novo)
    {
        return 0;
    }
    else
    {
        // Passo 2: armazenando 'numero' na posição recém-alocada
        novo->valor = numero;

        // Passo 3: fazer o novo nó apontar para o "antigo primeiro nó"
        novo->prox = *P;

        // Passo 4: fazer com que *P aponte para o novo Nó
        *P = novo;

        return 1;
    }
}