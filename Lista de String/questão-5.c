/* Lista de Exercícios VI (Strings):
   
   Questão 04:
   Implementar uma função que remova todas as ocorrências de determinado 
   caracter em uma string.
   
   observação: retornar o número de remoções realizadas.
*/

#include <stdio.h>

int removerCaracteres (char s[], char letra);

void main (void) {
	char s[20], letra;
	int ret;
	
	//lendo uma string para s
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (s);
	
	//Obtendo o caracter a ser removido
	printf ("\nEntre com o caracter a ser removido: ");
	fflush (stdin);
	scanf ("%c", &letra);
	
	//chamando a função
	ret = removerCaracteres (s, letra);
	
	//testando o retorno e exibindo a mensagem
	if (ret == 0) {
		printf ("\nNenhuma remocao realizada!\n", s);
	} else {
		printf ("\nForam feitas %d remocoes do caracter %c!\n", ret, letra);
		printf ("Novo conteudo da string: %s\n", s);
	}
}

//implementação das funções
int removerCaracteres (char s[], char letra) {
	int i, j, cont = 0;
	
	//percorrendo a string
	for (i = 0; s[i]; i++) {
		//verificando se 'letra' foi encontrada na string 's'
		if (s[i] == letra) {
			//deslocando os caracteres das próximas posições para a esquerda
			for (j = i; s[j]; j++) {
				s[j] = s[j + 1];
			}
			
			//atualizando a quantidade de remoções
			cont++;
		
			//garantindo que o 'i' ficará na mesma posição (compensando o i++ do for)	
			i--;
		}
	}
	
	//retornando a quantidade de remoções
	return cont;
}