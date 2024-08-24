/* Lista de Exercícios IV (Matrizes):
   
   QUESTÃO 04:
   Fazer uma função que, dada uma matriz Mn×n, determine se ela é simétrica.	
*/

#include <stdio.h>

void matriz(int x, int y, int m[x][y]);

int main(void) {
  int x, y;

  printf("Digie o número de linhas da matriz: ");
  scanf(" %d", &x);

  printf("Digie o número de colunas da matriz: ");
  scanf("%d", &y);

  int m[x][y];
  matriz(x, y, m);
  return 0;
}
void matriz(int x, int y, int m[x][y]) {
  //declaração de variáveis
	int i, j;
	
	if (x != y) {
		return 0;
	} else {
		for (i = 0; i < x; i++) {
			for (j = 0; j < y; j++) {
				if (m[i][j] != m[j][i]) {
					return 0;
				}
			}
		}
		return 1;
	}
}
