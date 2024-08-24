/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 29/05/2024

   Lista de Exercícios IX (Arquivos):

   Questão 01:
   Desenvolver uma função que, dado um arquivo texto, verifique
   o número de caracteres no mesmo.
*/

#include <stdio.h>

int numCaracteres(char nomeArq[]);

int main()
{
    char nome[30];
    int resposta;

    printf("Nome do arquivo: ");
    fflush(stdin);
    gets(nome);

    resposta = numCaracteres(nome);

    if (resposta == -1)
    {
        printf("\nO arquivo %s nao foi aberto!\n", nome);
    }
    else
    {
        printf("\nForam encontrados %d caracteres no arquivo %s.\n", resposta, nome);
    }
    return 0;
}

int numCaracteres(char nomeArq[])
{
    FILE *arq;
    char ch;
    int cont = 0;

    arq = fopen(nomeArq, "r");
    if (!arq)
    {
        return -1;
    }
    else
    {
        while (fscanf(arq, "%c", &ch) != EOF)
        {
            cont++;
        }
        fclose(arq);
        return cont;
    }
}