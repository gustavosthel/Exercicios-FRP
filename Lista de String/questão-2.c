/* Lista de Exercícios (String):

   Exercício 2: implementar uma função que, dada uma string s, determine se é
   ou não um palíndromo.
*/

#include <stdio.h>
#include <string.h>

// Protótipos das funções
int palindromo(char s[]);

// main
void main(void)
{
	char s[20];
	int ret;

	// lendo uma string para s
	printf("Entre com uma string: ");
	fflush(stdin);
	gets(s);

	// chamando a função
	ret = palindromo(s);

	// testando o retorno e exibindo a mensagem
	if (ret == 0)
	{
		printf("\nA string %s nao e um palindromo!\n", s);
	}
	else
	{
		printf("\nA string %s e um palindromo!\n", s);
	}
}

int palindromo(char s[])
{
	int i, j;

	// percorrendo a string
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		// verificando se os caracteres das posições 'i' e 'j' são distintos
		if (s[i] != s[j])
		{
			return 0;
		}
	}

	return 1;
}