/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 20/06/2024

   Lista de Exercícios IX (Arquivos):

   Questão 05:
    Desenvolver uma função que, dados dois
    arquivos textos arqA e arqB, crie um novo
    arquivo arqC, considerando que:
     arqA e arqB contém números reais,
    um por linha, ordenados
    crescentemente e sem repetição no
    arquivo;
     arqC deve conter todos os números
    dos dois arquivos originais;
     Assim como arqA e arqB, arqC
    também não possuirá repetições de
    elementos e estes deverão estar
    ordenados de forma crescente.
*/

// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int criarAquivoC(char NomeArqA[], char NomeArqB[], char NomeArqC[]);

int main()
{
}

int criarAquivoC(char NomeArqA[], char NomeArqB[], char NomeArqC[])
{
    FILE *arqA, *arqB, *arqC;
    int numA, numB, fimA = 0, fimB = 0;

    arqA = fopen(NomeArqA, "r");
    arqB = fopen(NomeArqB, "r");
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
        fscanf(arqA, "%d", &numA);
        fscanf(arqB, "%d", &numB);

        while (!fimA && !fimB)
        {
            if (numA < numB)
            {

                fprintf(arqC, "%d\n", numA);

                if (fscanf(arqA, "%d", &numA) == EOF)
                {
                    fimA = 1;
                }
            }
            else
            {
                if (numB < numA)
                {
                    fprintf(arqC, "%d\n", numB);

                    if (fscanf(arqB, "%d", &numB) == EOF)
                    {
                        fimB = 1;
                    }
                }
                else
                {
                    fprintf(arqC, "%d\n", numA);

                    if (fscanf(arqA, "%d", &numA) == EOF)
                    {
                        fimA = 1;
                    }

                    if (fscanf(arqB, "%d", &numB) == EOF)
                    {
                        fimB = 1;
                    }
                }
            }
        }
        // se chegou aqui, um (ou os dois) dos arquivos terminou
        // é necessário copiar os remanescentes do outro arquivo

        // verificar se A terminou, porém B contém elementos
        if (fimA && !fimB)
        {
            fprintf(arqC, "%.1f\n", numB);

            while (fscanf(arqB, "%f", &numB) != EOF)
            {
                fprintf(arqC, "%.1f\n", numB);
            }
        }

        // verificar se B terminou, porém A contém elementos
        if (fimB && !fimA)
        {
            fprintf(arqC, "%.1f\n", numA);

            while (fscanf(arqA, "%f", &numA) != EOF)
            {
                fprintf(arqC, "%.1f\n", numA);
            }
        }

        // fechando os arquivos
        fclose(arqA);
        fclose(arqB);
        fclose(arqC);

        return 1;
    }
}
