/*  (Arquivo)

    QUESTÃO:02
    Implementar uma função que, dados dois arquivos
    textos arquivoA e arquivo, contendo números inteiros,
    um por linha, sem repetições, determine o número de
    elementos comuns entre os dois arquivos.
*/

// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int contandoIquais(char nomeArqA[], char nomeArqB[]);

int main()
{
    int result = contandoIquais("C:/Users/pcasa/OneDrive/Área de Trabalho/aquuvos/arquivoA.txt",
                                "C:/Users/pcasa/OneDrive/Área de Trabalho/aquuvos/arquivoB.txt");

    if (!result)
    {
        printf("Erro ao abrir o arquivo!");
    }
    else
    {
        printf("Numeros iquais: %d", result);
    }
}

int contandoIquais(char nomeArqA[], char nomeArqB[])
{
    FILE *arqA, *arqB;
    int num1, num2, cont = 0;

    arqA = fopen(nomeArqA, "r");
    arqB = fopen(nomeArqB, "r");

    if (!arqA || !arqB)
    {
        fclose(arqA);
        fclose(arqB);
        return 0;
    }
    else
    {
        while (fscanf(arqA, "%d", &num1) != EOF)
        {
            while (fscanf(arqB, "%d", &num2) != EOF)
            {
                if (num1 == num2)
                {
                    cont++;
                }
            }
            rewind(arqB);
        }
        return cont;
    }
}
