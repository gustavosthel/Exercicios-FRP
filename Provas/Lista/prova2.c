/*  (Lista Encadeada)

    QUESTÃO 02:
    Considere uma lista, encadeada, da qual cada nó
    possui, além dos campos valor (do tipo char) e prox, um
    campo ant que aponta para o nó anterior, caso este
    exista. Além disso, dois ponteiros são armazenados em
    um vetor de tamanho 2, do qual a primeira posição
    aponta para o primeiro nó da estrutura e o segundo
    guarda o endereço do último nó da lista. Pede-se:
    1. A declaração do tipo que representa cada nó
    da lista;
    2. A declaração de uma variável que represente o
    vetor de dois ponteiros;
    3. Uma função que verifique se a palavra
    formada pelos caracteres armazenados na
    lista consiste em um palíndromo

*/

#include <stdio.h>
#include <stdlib.h>

#define tamanho 2

typedef struct No
{
    char valor;
    struct No *prox;
    struct No *ant;
} TNo;

typedef TNo *TLista[2];

int decobrePalindromo(TLista lista);
void inserir(TLista lista, char valor);
void exibir(TLista lista);

int main()
{
    TLista lista = {NULL, NULL};

    inserir(lista, 'r');
    inserir(lista, 'a');
    inserir(lista, 'd');
    inserir(lista, 'a');
    inserir(lista, 'r');

    exibir(lista);

    if (decobrePalindromo(lista))
    {
        printf("A palavra e um palindromo.\n");
    }
    else
    {
        printf("A palavra nao e um palindromo.\n");
    }
}

int decobrePalindromo(TLista lista)
{

    if (!lista[0])
    {
        return 1;
    }
    else
    {
        TNo *inicio = lista[0];
        TNo *fim = lista[1];

        while (inicio != fim && fim->prox != inicio)
        {
            if (inicio->valor != fim->valor)
            {
                return 0;
            }
            inicio = inicio->prox;
            fim = fim->ant;
        }
        return 1;
    }
}

// Função para inserir um novo caractere no final da lista
void inserir(TLista lista, char valor)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    if (novo == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = lista[1];

    if (lista[1] != NULL)
    {
        lista[1]->prox = novo;
    }
    lista[1] = novo;

    if (lista[0] == NULL)
    {
        lista[0] = novo;
    }
}

// Função para exibir a lista
void exibir(TLista lista)
{
    TNo *atual = lista[0];
    while (atual != NULL)
    {
        printf("%c ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}