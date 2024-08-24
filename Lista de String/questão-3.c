/* Strings:
   
   Exercício 3: dada uma string s, implementar uma função que inverta n 
   caracteres a partir da posição p.
   
   Observações:
   	- Caso p seja inválido, a função deverá retornar 0;
   	- Caso não existam n caracteres a partir da posição p, a função deverá
   	  inverter os caracteres da posição p à última posição da string.
   	- Caso a inversão seja possível, o valor 1 será retornado.
*/

#include <stdio.h>
#include <string.h>

int inverter (char s[], int p, int n);


void main(void) {

	char s[20];
	int ret, n, p;
	
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (s);
	
	//Obtendo os valores de p e de n
	printf ("\nEntre com a posição: ");
	scanf ("%d", &p);
	
	printf ("\nEntre com a quantidade de caracteres: ");
	scanf ("%d", &n);
	
	//chamando a função
	ret = inverter (s, p, n);
	
	//testando o retorno e exibindo a mensagem
	if (ret == 0) {
		printf ("\nA string %s nao foi invertida!\n", s);
	} else {
		printf ("\nConteudo da string apos a inversao: %s!\n", s);
	}
}

int inverter (char s[], int p, int n) {
	//declaração de variáveis
	int i, j, tamanho = strlen(s), posicao;
	char aux;
	
	if ((p < 0) || (p >= tamanho) || (n <= 0)) {
		return 0;
	}
	
	//determinando a posição final da troca
	if (n+p-1 < tamanho-1) {
		posicao = n+p-1;
	} else {
		posicao = tamanho-1;
	}
	
	//realizando a troca dos caracteres da posição 'p' à posição 'posicao'
	for (i = p, j = posicao; i < j; i++, j--) {
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
}