/* Lista de Exercícios VIII (Recursividade)
   
   Questão 02: 
   Fazer uma função recursiva que, dado um número inteiro N, exiba 
   o mesmo na base 2 (binária).
*/

#include <stdio.h>


void binario (int n);

void main(void) {
	binario (32);
}

void binario (int n) {
	if (n == 0) {
		printf ("0");
	} else {
		if (n > 0) {
			binario (n/2);
			
			printf ("%d", n%2);
		}
	}
}