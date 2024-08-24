/* Lista de Exercícios VIII (Recursividade)
   
   Questão 01: 
   Desenvolver uma função recursiva que exiba todos os múltiplos 
   do número N, inferiores ou iguais ao valor V.
*/

#include <stdio.h>

void exibirMultiplosAux (int N, int V, int aux);
void exibirMultiplos (int N, int V);

void main(void) {
	exibirMultiplos (5, 30);
}

void exibirMultiplos (int N, int V) {
	exibirMultiplosAux (0, V, N);	
}

void exibirMultiplosAux (int N, int V, int aux) {
	if (N <= V) {
		printf ("%d ", N);
		
		exibirMultiplosAux (N+aux, V, aux);
	}
}



