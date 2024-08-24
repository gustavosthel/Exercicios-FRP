/* Lista de Exercícios IX (Listas Encadeadas):

    QUESTÃO 02:
    Dada uma fila F, do tipo TLista, implementar
    uma função que remova de F todos os divisores
    do número inteiro N e, ao final, retorne a
    quantidade de remoções realizadas.

    Notas: i. as regras de manipulação de uma fila
    clássica devem ser respeitadas; ii. Caso alguma
    estrutura auxiliar seja necessária, esta deverá
    ser uma fila ou uma pilha.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int removerDivisores(TLista *F, TLista *U, int numero);
int enfileirar(TLista *F, TLista *U, int numero);
int desenfileirar(TLista *F, TLista *U, int *numero);

int main()
{
    TLista F = NULL, U = NULL;
    int resul;

    enfileirar(&F, &U, 9);
    enfileirar(&F, &U, 18);
    enfileirar(&F, &U, 7);
    enfileirar(&F, &U, 21);
    enfileirar(&F, &U, 6);
    enfileirar(&F, &U, 14);

    resul = removerDivisores(&F, &U, 7);

    printf("Foram removidos %d elementos da fila\n", resul);

    // Exibir a fila restante
    int num;
    while (desenfileirar(&F, &U, &num))
    {
        printf("%d ", num);
    }
    printf("\n");

    return 0;
}

int removerDivisores(TLista *F, TLista *U, int numero)
{
    TLista auxF = NULL, auxU = NULL;
    int num, removidos = 0;

    while (desenfileirar(F, U, &num))
    {
        if (num % numero != 0)
        {
            enfileirar(&auxF, &auxU, num);
        }
        else
        {
            removidos++;
        }
    }

    // Transferir de volta os elementos para a fila original
    while (desenfileirar(&auxF, &auxU, &num))
    {
        enfileirar(F, U, num);
    }

    return removidos;
}

int enfileirar(TLista *F, TLista *U, int numero)
{
    TLista aux;

    aux = (TLista)malloc(sizeof(TNo));
    if (!aux)
    {
        return 0;
    }

    aux->valor = numero;
    aux->prox = NULL;

    if (*U)
    {
        (*U)->prox = aux;
    }
    else
    {
        *F = aux;
    }
    *U = aux;

    return 1;
}

int desenfileirar(TLista *F, TLista *U, int *numero)
{
    TLista aux;

    if (*F)
    {
        aux = *F;
        *F = aux->prox;

        if (!(*F))
        {
            *U = NULL;
        }

        *numero = aux->valor;
        free(aux);

        return 1;
    }
    else
    {
        return 0;
    }
}