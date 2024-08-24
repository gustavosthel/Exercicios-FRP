/* Lista de Exercícios VIII (Recursividade)
   
   Questão 03: 
   Pede-se a implementação de uma função recursiva que exiba os 
   n primeiros termos de uma PG (Progressão Geométrica), onde a1 
   é o seu primeiro termo e q a razão.
   
   Observação: uma PG consiste em uma sequência de valores, 
   iniciadas pelo valor a1. Os demais elementos são definidos 
   como o anterior multiplicado pela razão.
   
   Exemplo:
   
   n = 5
   a1 = 2
   q = 3
   
   PG: 2 6 18 54 162
*/

#include <stdio.h>

void PG (int a1, int q, int n);

void main(void) {
	PG (2, 3, 5);
}

void PG (int a1, int q, int n) {
	if (n > 0) {
		printf ("%d ", a1);
		
		PG (a1*q, q, n-1);
	}
}