/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 29/05/2024

   Lista de Exercícios IX (Arquivos):

   Questão 03:
   Desenvolver uma função que, dado um arquivo texto, verifique o
   número de letras existentes no mesmo (entendendo que no arquivo
   podem existir letras, algarismos e símbolos).
*/

#include <stdio.h>

int numOcorrencias(char nomeArq[]);

int main()
{
    char nome[30];
    int resposta;

    printf("Nome do arquivo: ");
    fflush(stdin);
    gets(nome);

    resposta = numOcorrencias(nome);

    if (resposta == -1)
    {
        printf("\nO arquivo %s nao foi aberto!\n", nome);
    }
    else
    {
        printf("\nForam encontrados %d ocorrencias do caracter %c no arquivo %s.\n", resposta, nome);
    }
}

int numOcorrencias(char nomeArq[])
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
            ch = toupper(ch);
            if (ch >= 'A' && ch <= 'Z')
            {
                cont++;
            }
        }

        fclose(arq);
        return cont;
    }
}