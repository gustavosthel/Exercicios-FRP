/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 29/05/2024

   Lista de Exercícios IX (Arquivos):

   Questão 04:
   Desenvolver uma função que, dado um arquivo texto contendo
   números, determine se estes encontram-se ordenados crescentemente.
*/

#include <stdio.h>
#include <limits.h>

int verificandoOrdenado(char nomeArq[]);

int main()
{
    char nome[30];
    int resposta;

    printf("Nome do arquivo: ");
    fflush(stdin);
    gets(nome);

    resposta = verificandoOrdenado(nome);

    if (resposta == -1)
    {
        printf("\nO arquivo %s nao foi aberto!\n", nome);
    }
    else
    {
        printf("\nForam encontradas %d letras no arquivo %s.\n", resposta, nome);
    }
}

int verificandoOrdenado(char nomeArq[])
{
    FILE *arq;
    int numero;
    int anterio = INT_MIN;

    arq = fopen(nomeArq, "r");

    if (!arq)
    {
        return -1;
    }
    else
    {

        while (fscanf(arq, "%c", &numero) != EOF)
        {
            if (numero < anterio)
            {
                fclose(arq);
                return 0;
            }
            anterio = numero;
        }

        fclose(arq);
        return 1;
    }
}