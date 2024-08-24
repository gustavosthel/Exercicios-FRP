/*  (Arquivo)

    QUESTÃO:01
    Dado um arquivo texto, contendo números inteiros, um
    por linha, criar um arquivo novo.txt apenas com os
    elementos do original que, na ordem que foram lidos,
    fazem com que o novo arquivo esteja ordenado
    crescentemente. Todos os demais valores que
    “atrapalharam” essa ordenação serão armazenados em
    no arquivo descartados.txt.
*/

// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int organizandoArquivos(char NomeArqA[], char NomeArqB[], char NomeArqC[]);

int main()
{
    int result = organizandoArquivos("C:/Users/pcasa/OneDrive/Área de Trabalho/aquuvos/arquivoA.txt",
                                     "C:/Users/pcasa/OneDrive/Área de Trabalho/aquuvos/arquivoB.txt",
                                     "C:/Users/pcasa/OneDrive/Área de Trabalho/aquuvos/arquivoC.txt");

    if (result == 1)
    {
        printf("Arquivos organizados com sucesso!\n");
    }
    else
    {
        printf("Falha ao organizar arquivos.\n");
    }
}

int organizandoArquivos(char NomeArqA[], char NomeArqB[], char NomeArqC[])
{
    FILE *arqA, *arqB, *arqC;
    int num1;
    int anterio = INT_MIN;

    arqA = fopen(NomeArqA, "r");
    arqB = fopen(NomeArqB, "w");
    arqC = fopen(NomeArqC, "w");

    if (!arqA || !arqB || !arqC)
    {
        fclose(arqA);
        fclose(arqB);
        fclose(arqC);
        return 0;
    }
    else
    {
        while (fscanf(arqA, "%d", &num1) != EOF)
        {
            if (num1 < anterio)
            {
                fprintf(arqC, "%d\n", num1);
            }
            else
            {
                fprintf(arqB, "%d\n", num1);
                anterio = num1;
            }
        }
    }
    fclose(arqA);
    fclose(arqB);
    fclose(arqC);

    return 1;
}
