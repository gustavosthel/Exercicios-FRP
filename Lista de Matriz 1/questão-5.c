/* Lista de Exercícios IV (Matrizes):
   
   QUESTÃO 05:
   Implementar uma função que, dada uma matriz Mm×n, gere um vetor V de 
   tamanho n, onde cada elemento do vetor consiste na soma dos elementos 
   de uma coluna de M. Ou seja, o elemento V[0] consiste na soma dos 
   elementos da primeira coluna de M, o elemento V[1] consiste na soma 
   dos elementos da segunda coluna de M, e assim por diante.	
*/

#include <stdio.h>

void amazenar(int x, int y, int m[x][y], int v[], int tamanho);

int main(void) {
  int x, y, k = 1;

  printf("Digite o valor de n: ");
  scanf("%d", &x);

  printf("Digite o valor de m: ");
  scanf("%d", &y);

  int m[x][y];

  printf("\nMatriz:\n");
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      m[i][j] = k;
      printf("%d ", m[i][j]);
      k++;
    }
    printf("\n");
  }

   int v[y];
  
  amazenar(x, y, m, v, y);

  printf("\nSomas das colunas:\n");
  int i;
  for (i = 0; i < y; i++) {
      printf("Soma da coluna %d: %d\n", i + 1, v[i]);
  }
  
  return 0;
}
void amazenar(int x, int y, int m[x][y], int v[], int tamanho) {
  int i, j, soma;

    for (j = 0; j < y; j++) {
      soma = 0;
      for (i = 0; i < x; i++) {
        soma += m[i][j];
      }
       v[j] = soma;
    }
}
