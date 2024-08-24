/* Lista de Exercícios IV (Matrizes):
   
   QUESTÃO 01:
   Faça uma função que, dada uma matriz Mm×n de reais, gere a matriz Mt, 
   sua transposta.
*/

#include <stdio.h>

void matrizTransposta(int x, int y, int m[x][y]);

int main(void) {
  int x, y, k = 1;

  printf("Digite o valor de x: ");
  scanf("%d", &x);

  printf("Digite o valor de y: ");
  scanf("%d", &y);

  int m[x][y];
  
  printf("\nMatriz original:\n");
  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      m[i][j] = k;
      printf("%d ", m[i][j]);
      k++;
    }
    printf("\n");
  }
  
  printf("Matriz transposta:\n");
  matrizTransposta(x, y, m);
  return 0;
}
void matrizTransposta(int x, int y, int m[x][y]) {
  int i, j;

  for (j = 0; j < y; j++) {
    for (i = 0; i < x; i++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}
