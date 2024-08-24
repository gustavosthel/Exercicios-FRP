/* Lista de Exercícios V (Matrizes):
   
   Questão 01:
   Considerando a existência de uma matriz de inteiros M, de 
   ordem N (ou seja, o nº de linhas e o nº de colunas são 
   iguais a N), onde N é uma constante, desenvolver uma função 
   que retorne 1 se a seguinte regra for atendida por M (caso 
   contrário, o valor 0 deverá ser retornado):
   
   A soma dos elementos da diagonal principal deve ser igual 
   à soma dos elementos que estão acima desta diagonal, assim 
   como à soma dos elementos abaixo da diagonal.
*/

#include <stdio.h>

int somandoMatriz(int x, int y, int m[x][y]);

int main() {
  int i, j, k = 1,x = 5, y = 5, m[x][y];
  
  printf("\nMatriz:\n");
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      m[i][j] = k;
      printf("%d ", m[i][j]);
      k++;
    }
    printf("\n");
  }

  int resultado = somandoMatriz(x, y, m);
  if (resultado == 1) {
    printf("\nSomas iguais!\n");
  } else {
    printf("\nSomas diferentes!\n");
  }
  
  return 0;
}
int somandoMatriz(int x, int y, int m[x][y]) {
  int i, j, soma1 = 0, soma2 = 0;

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (i > j) {
        soma1 += m[i][j];
      } else if (i < j) {
        soma2 += m[i][j];
      }
    }
  }
  if (soma1 == soma2) {
    return 1;
  } else {
    return 0;
  }
}