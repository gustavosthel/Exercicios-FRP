/*  (Arquivo)

    QUESTÃO:03
    Implementar uma função que, dados dois arquivos
    textos arquivoA e arquivoB, contendo números inteiros,
    um por linha, determine o número de
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
    FILE *arqA, *arqB, *auxA;
    int num1, num2, auxNum, cont = 0, encontradoEmB, encontradoEmA;

    arqA = fopen(nomeArqA, "r");
    arqB = fopen(nomeArqB, "r");
    auxA = fopen("auxA.txt", "w+");

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
            encontradoEmA = 0;
            rewind(auxA);

            while (fscanf(auxA, "%d", &auxNum) != EOF)
            {
                if (num1 == auxNum)
                {
                    encontradoEmA = 1;
                    break;
                }
            }

            if (encontradoEmA)
            {
                continue;
            }

            rewind(arqB);
            encontradoEmB = 0;
            while (fscanf(arqB, "%d", &num2) != EOF)
            {
                if (num1 == num2 && encontradoEmB == 0)
                {
                    cont++;
                    encontradoEmB = 1;
                }
            }

            fprintf(auxA, "%d\n", num1);
        }

        fclose(arqA);
        fclose(arqB);
        fclose(auxA);

        remove("auxA");

        return cont;
    }
}
