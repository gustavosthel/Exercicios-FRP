/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 20/06/2024

   Lista de Exercícios IX (Arquivos):

   Questão 05:
   Faça uma função que, dado um arquivo A contendo números reais,
   um por linha, crie um novo arquivo B contendo os mesmos
   elementos de A, porém ordenados decrescentemente e sem
   repetição.
*/

// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// protótipos das funções
int criarArquivoOrdenado(char nomeArqA[], char nomeArqB[]);
int buscarMaiorElemento(char nomeArq[], float limite, float *valor);

// main
void main()
{
	criarArquivoOrdenado("teste.txt", "novo.txt");
}

// implementação das funções
int criarArquivoOrdenado(char nomeArqA[], char nomeArqB[])
{
	// declaração de variáveis
	FILE *arqB;
	float valor, limite = FLT_MAX;

	// abrindo o arquivo B
	arqB = fopen(nomeArqB, "w");

	// verificando se houve erro na abertura do arquivo
	if (!arqB)
	{
		return 0;
	}
	else
	{
		// enquanto existirem elementos no arquivo A...
		while (buscarMaiorElemento(nomeArqA, limite, &valor))
		{
			// escreva no arquivo B o valor retornado
			fprintf(arqB, "%.1f\n", valor);

			// atualizando o limite
			limite = valor;
		}

		fclose(arqB);

		return 1;
	}
}

int buscarMaiorElemento(char nomeArq[], float limite, float *valor)
{
	// declaração de variáveis
	FILE *arq;
	float numero;
	int achou = 0;

	// inicializando o valor a ser retornado
	*valor = FLT_MIN;

	// abrindo o arquivo
	arq = fopen(nomeArq, "r");

	// testando se o arquivo foi aberto
	if (!arq)
	{
		return -1;
	}
	else
	{
		while (fscanf(arq, "%f", &numero) != EOF)
		{
			// verificando se o valor lido é inferior ao limite
			if ((numero < limite) &&
				(numero > *valor)) // verificando seé o maior até o momento
			{
				*valor = numero;
				achou = 1;
			}
		}

		fclose(arq);

		return achou;
	}
}