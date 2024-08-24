/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 29/05/2024

   Lista de Exercícios IX (Arquivos):

   Questão 02:
   Desenvolver uma função que, dado um arquivo texto, verifique o
   número de vezes que um determinado caracter aparece no arquivo.
*/

#include <stdio.h>

int verficandoCaracter(char nomeArq[], char caracter);

int main()
{
    char nome[30];
    int resposta;
    char c;

    printf("Nome do arquivo: ");
    fflush(stdin);
    gets(nome);

    printf("Caracter a ser buscado: ");
    fflush(stdin);
    scanf("%c", &c);

    resposta = verficandoCaracter(nome, c);

    if (resposta == -1)
    {
        printf("\nO arquivo %s nao foi aberto!\n", nome);
    }
    else
    {
        printf("\nForam encontrados %d caracteres no arquivo %s.\n", resposta, nome);
    }
}

int verficandoCaracter(char nomeArq[], char caracter)
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
            if (ch == caracter)
            {
                cont++;
            }
            fclose(arq);
            return cont;
        }
    }
}