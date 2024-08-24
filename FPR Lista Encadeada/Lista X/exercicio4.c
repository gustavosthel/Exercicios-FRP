/* Lista de Exercícios X (Listas Encadeadas):

   QUESTÃO 04:
   Implementar uma função que, dadas duas listas dinâmicas do
   tipo TLista, verifique se estas são iguais; isto é, contêm
   os mesmos elementos, na mesma ordem.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} TNo;

typedef TNo *TLista;

int verificarIqual(TLista l1, TLista l2);
int inserir(TLista *L, int numero);
void exibir(TLista L);

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
    inserir(&L2, 10);
    inserir(&L2, 4);
    inserir(&L2, 13);
    inserir(&L2, 7);

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
    if (verificarIqual(L1, L2) == 1)
    {
        printf("\n\nL1 e L2 possuem os mesmos elementos, na mesma ordem!\n\n");
    }
    else
    {
        printf("\n\nL1 e L2 NAO possuem os mesmos elementos, na mesma ordem!\n\n");
    }

    if (verificarIqual(L1, L3) == 1)
    {
        printf("\n\nL1 e L3 possuem os mesmos elementos, na mesma ordem!\n\n");
    }
    else
    {
        printf("\n\nL1 e L3 NAO possuem os mesmos elementos, na mesma ordem!\n\n");
    }
}

int verificarIqual(TLista l1, TLista l2)
{
    // declarando variáveis
    TLista aux1 = l1;
    TLista aux2 = l2;

    // percorendo as listas
    while (aux1 && aux2)
    {
        // verificando se os elementos sao diferentes
        if (aux1->valor != aux2->valor)
        {
            // caso seja ele ja retonar 0
            return 0;
        }

        // apontando para o procimo elemento
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    // se chegou aqui e por que os elementos das duas listas sao iquais
    // então verifico se chegaram no final das duas lista
    if (!aux1 && !aux2)
    {
        // se chegou ele retona 1 (verdade)
        return 1;
    }
    else
    {
        // se não ele retona 0 (uma das lista nao foi ate o final)
        return 0;
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
