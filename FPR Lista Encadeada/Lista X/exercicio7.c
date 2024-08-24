/* Lista de Exercícios X (Listas Encadeadas):

    QUESTÃO 07:
    Desenvolver uma função que insira um número inteiro N na
    i-ésima posição de uma lista encadeada L.

    Observação: caso a posição i informada seja inválida, a função
    deverá retornar o valor 0; caso contrário, o retorno será
    igual a 1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int inserirNumero(TLista *L, int numero, int posisao);
void exibir(TLista L);

int main()
{
    // declaração de variáveis
    TLista L = NULL;

    // inserindo elementos em L
    if (inserirNumero(&L, 10, 2))
    {
        printf("\nO valor 10 foi inserido na lista!\n");
    }
    else
    {
        printf("\nO valor 10 NAO foi inserido na lista!\n");
    }

    if (inserirNumero(&L, 4, 1))
    {
        printf("\nO valor 4 foi inserido na lista!\n");
    }
    else
    {
        printf("\nO valor 4 NAO foi inserido na lista!\n");
    }

    if (inserirNumero(&L, 3, 2))
    {
        printf("\nO valor 3 foi inserido na lista!\n");
    }
    else
    {
        printf("\nO valor 3 NAO foi inserido na lista!\n");
    }

    if (inserirNumero(&L, 5, 0))
    {
        printf("\nO valor 5 foi inserido na lista!\n");
    }
    else
    {
        printf("\nO valor 5 NAO foi inserido na lista!\n");
    }

    if (inserirNumero(&L, 6, 2))
    {
        printf("\nO valor 6 foi inserido na lista!\n");
    }
    else
    {
        printf("\nO valor 6 NAO foi inserido na lista!\n");
    }

    if (inserirNumero(&L, 15, 4))
    {
        printf("\nO valor 15 foi inserido na lista!\n");
    }
    else
    {
        printf("\nO valor 15 NAO foi inserido na lista!\n");
    }

    // exibindo a lista L
    exibir(L);
}

int inserirNumero(TLista *L, int numero, int posisao)
{
    TLista aux1, aux2;
    int cont = 1;
    TLista novo;

    if (posisao < 1)
    {
        return 0;
    }
    else
    {
        if (posisao == 1)
        {
            novo = (TLista)malloc(sizeof(TNo));

            if (novo)
            {
                novo->valor = numero;

                novo->prox = *L;
                *L = novo;

                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (!(*L))
            {
                return 0;
            }

            aux1 = *L;
            aux2 = aux1->prox;

            while ((aux2) && (cont < posisao - 1))
            {
                cont++;
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }

            if (cont == posisao - 1)
            {
                novo = (TLista)malloc(sizeof(TNo));

                if (novo)
                {
                    novo->valor = numero;

                    aux1->prox = novo;
                    novo->prox = aux2;

                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
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