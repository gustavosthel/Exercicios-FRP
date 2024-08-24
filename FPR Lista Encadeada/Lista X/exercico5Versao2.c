#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

// protótipos das funções
int compararListas(TLista lista1, TLista lista2);
int verificarMesmosElementos(TLista lista1, TLista lista2);
int inserir(TLista *L, int numero);
void exibir(TLista L);
int buscar(TLista L, int numero);

int main()
{
    // declaração de variáveis
    TLista L1 = NULL, L2 = NULL, L3 = NULL;

    // inserindo elementos em L1
    inserir(&L1, 10);
    inserir(&L1, 4);
    inserir(&L1, 13);
    inserir(&L1, 7);

    // inserindo elementos em L2
    inserir(&L2, 7);
    inserir(&L2, 4);
    inserir(&L2, 10);
    inserir(&L2, 13);

    // inserindo elementos em L3
    inserir(&L3, 10);
    inserir(&L3, 4);
    inserir(&L3, 13);
    inserir(&L3, 7);
    inserir(&L3, 5);

    // exibindo as listas
    exibir(L1);
    exibir(L2);
    exibir(L3);

    // chamando a função
    if (compararListas(L1, L2) == 1)
    {
        printf("\n\nL1 e L2 possuem os mesmos elementos!\n\n");
    }
    else
    {
        printf("\n\nL1 e L2 NAO possuem os mesmos elementos!\n\n");
    }

    if (compararListas(L1, L3) == 1)
    {
        printf("\n\nL1 e L3 possuem os mesmos elementos!\n\n");
    }
    else
    {
        printf("\n\nL1 e L3 NAO possuem os mesmos elementos!\n\n");
    }
}

int compararListas(TLista lista1, TLista lista2)
{
    return verificarMesmosElementos(lista1, lista2) &&
           verificarMesmosElementos(lista2, lista1);
}

int verificarMesmosElementos(TLista lista1, TLista lista2)
{
    TLista aux = lista1;

    while (aux)
    {
        if (buscar(lista2, aux->valor) == 0)
        {
            return 0;
        }

        aux = aux->prox;
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

int buscar(TLista L, int numero)
{
    // declaração de variáveis
    TLista aux = L;

    // percorrendo os elementos da lista
    while (aux)
    {
        // verificando se 'numero' foi encontrado
        if (aux->valor == numero)
        {
            return 1;
        }

        aux = aux->prox;
    }

    //'numero' não se encontra na lista
    return 0;
}