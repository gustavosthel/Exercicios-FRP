/*  (Fila e pilha)

    QUESTÃO 03:
    Suponha a existência de uma fila F, do tipo TLista,
    armazenando n elementos, e uma pilha P, também do
    tipo TLista. Desenvolver uma função que remova de F
    todos os seus elementos que também estão em P.


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

// Funções auxiliares

int enfilar(TLista *F, TLista *U, int numero);
int desenfilar(TLista *F, TLista *U, int *numero);
int empilhar(TLista *P, int numero);
int desempilhar(TLista *P, int *numero);
int estaNaPilha(TLista *pilha, int valor);
void exibirLista(TLista lista);
void removerElementos(TLista *F, TLista *U, TLista *P);

// Função principal

int main()
{
    TLista fila = NULL;
    TLista fimFila = NULL;
    TLista pilha = NULL;

    // Inserir elementos na fila
    enfilar(&fila, &fimFila, 1);
    enfilar(&fila, &fimFila, 2);
    enfilar(&fila, &fimFila, 3);
    enfilar(&fila, &fimFila, 4);
    enfilar(&fila, &fimFila, 5);

    // Inserir elementos na pilha
    empilhar(&pilha, 3);
    empilhar(&pilha, 5);

    printf("Fila antes da remocao:\n");
    exibirLista(fila);

    printf("Pilha:\n");
    exibirLista(pilha);

    // Remover elementos da fila que estão na pilha
    removerElementos(&fila, &fimFila, &pilha);

    printf("Fila apos a remocao:\n");
    exibirLista(fila);

    return 0;
}

// Função para verificar se um elemento está na pilha

int estaNaPilha(TLista *pilha, int valor)
{
    TLista auxPilha = NULL;
    int numero;
    int verificar = 0;

    while (*pilha)
    {
        desempilhar(pilha, &numero);
        if (numero == valor)
        {
            verificar = 1;
        }
        empilhar(&auxPilha, numero);
    }

    while (auxPilha)
    {
        desempilhar(&auxPilha, &numero);
        empilhar(pilha, numero);
    }

    return verificar;
}

// Função para remover elementos da fila que estão na pilha

void removerElementos(TLista *F, TLista *U, TLista *P)
{
    TLista auxFila = NULL;
    TLista fimAuxFila = NULL;
    int valor;

    while (*F != NULL)
    {
        desenfilar(F, U, &valor);
        if (!estaNaPilha(P, valor))
        {
            enfilar(&auxFila, &fimAuxFila, valor);
        }
    }

    while (auxFila != NULL)
    {
        desenfilar(&auxFila, &fimAuxFila, &valor);
        enfilar(F, U, valor);
    }
}

// Função para exibir a lista

void exibirLista(TLista lista)
{
    TLista atual = lista;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Funções auxiliares fornecidas

int enfilar(TLista *F, TLista *U, int numero)
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

        // fazendo o campo 'prox' do novo nó apontar para NULL (uma vez que será o últim da fila)
        aux->prox = NULL;

        // verificando se existem elementos na fila
        if (*F) // poderia também ser:   if (*U)
        {
            // fazendo o campos 'prox' do último da fila apontar para o novo nó
            (*U)->prox = aux;
        }
        else
        {
            // atualizando o 'F', de forma a apontar para o novo nó
            *F = aux;
        }

        // atualizando 'U'
        *U = aux; // ou:   *U = (*U)->prox;

        return 1;
    }
}

int desenfilar(TLista *F, TLista *U, int *numero)
{
    // declaração de variáveis
    TLista aux;

    // verificando se a fila possui elementos
    if (*F)
    {
        // aux guardando o endereço do nó que será removido
        aux = *F;

        // fazendo *F apontar para o "antigo segundo nó"
        *F = aux->prox; // ou   *F = (*F)->prox;

        // verificando se a fila se tornou vazia
        if (!(*F))
        {
            *U = NULL;
        }

        // armazenando no parâmetro 'numero' o valor que era o primeiro da fila
        *numero = aux->valor;

        // liberando a memória do nó a ser removido
        free(aux);

        return 1;
    }
    else
    {
        return 0;
    }
}

int empilhar(TLista *P, int numero)
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
        aux->prox = *P;

        // Passo 4: fazer com que *P aponte para o novo Nó
        *P = aux;

        return 1;
    }
}

int desempilhar(TLista *P, int *numero)
{
    // declaração de variáveis
    TLista aux;

    // verificando se a pilha possui elementos
    if (*P)
    {
        // aux guardando o endereço do nó que será removido
        aux = *P;

        // fazendo *P apontar para o "antigo segundo nó"
        *P = aux->prox; // ou   *P = (*P)->prox;

        // armazenando no parâmetro 'numero' o valor que estava no topo da pilha
        *numero = aux->valor;

        // liberando a memória do nó a ser removido
        free(aux);

        return 1;
    }
    else
    {
        return 0;
    }
}