/*  (Fila e pilha)

    QUESTÃO 04:
    Para cada uma das estruturas apresentadas abaixo,
    descrever o algoritmo que permite a remoção de todas
    as ocorrências de determinado número, considerando
    a implementação clássica dessas estruturas:
    a. Uma pilha;
    b. Uma fila.
    Notas:
    i. Os elementos remanescentes devem
    permanecer na mesma ordem original;
    ii. Caso alguma estrutura auxiliar seja
    necessária, ela poderá ser uma pilha ou uma
    fila (devendo especificar qual foi utilizada na
    solução).


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

// Funções auxiliares fila
void removerOcorencias(TLista *F, TLista *U, int numero);
int enfilar(TLista *F, TLista *U, int numero);
int desenfilar(TLista *F, TLista *U, int *numero);
void exibirLista(TLista lista);

// Funções auxiliares pilha
int empilhar(TLista *P, int numero);
int desempilhar(TLista *P, int *numero);
void removerOcorenciasPilha(TLista *P, int numero);

int main()
{
    TLista fila = NULL;
    TLista fimFila = NULL;
    TLista pilha = NULL;

    // Inserir elementos na fila
    enfilar(&fila, &fimFila, 1);
    enfilar(&fila, &fimFila, 2);
    enfilar(&fila, &fimFila, 3);
    enfilar(&fila, &fimFila, 2);
    enfilar(&fila, &fimFila, 5);

    exibirLista(fila);

    removerOcorencias(&fila, &fimFila, 2);

    exibirLista(fila);

    printf("\nSeguda parte!\n");
    empilhar(&pilha, 1);
    empilhar(&pilha, 2);
    empilhar(&pilha, 3);
    empilhar(&pilha, 4);
    empilhar(&pilha, 2);
    empilhar(&pilha, 6);

    exibirLista(pilha);

    removerOcorenciasPilha(&pilha, 2);

    exibirLista(pilha);
}

void removerOcorencias(TLista *F, TLista *U, int numero)
{
    TLista auxFila = NULL;
    TLista fimAuxFila = NULL;
    int valor;

    while (*F)
    {
        desenfilar(F, U, &valor);
        if (numero != valor)
        {
            enfilar(&auxFila, &fimAuxFila, valor);
        }
    }

    while (auxFila)
    {
        desenfilar(&auxFila, &fimAuxFila, &valor);
        enfilar(F, U, valor);
    }
}

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

// parte da fila

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

// parte da pilha

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

void removerOcorenciasPilha(TLista *P, int numero)
{
    TLista auxPilha = NULL;
    int valor;

    while (*P)
    {
        desempilhar(P, &valor);
        if (numero != valor)
        {
            empilhar(&auxPilha, valor);
        }
    }

    while (auxPilha)
    {
        desempilhar(&auxPilha, &valor);
        empilhar(P, valor);
    }
}
