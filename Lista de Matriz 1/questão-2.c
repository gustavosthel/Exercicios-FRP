/* Lista de Exercícios IV (Matrizes):
   
   QUESTÃO 02:
   Desenvolver uma função que, dada uma matriz Mm×n, determine se um número 
   X se encontra na linha L da matriz.
*/


#include <stdio.h>

void matriz(int n, int m, int ma[n][m], int x, int l);

int main() {
  int n, m, x, l;

  printf("Digite o valor de n: ");
  scanf("%d", &n);

  printf("Digite o valor de m: ");
  scanf("%d", &m);

  printf("Digite o valor de x: ");
  scanf("%d", &x);

  printf("Digite o número da linha (L) que deseja verificar: ");
  scanf("%d", &l);

  int ma[n][m];
  int k = 1;
  
  printf("\nMatriz:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ma[i][j] = k;
      printf("%d ", ma[i][j]);
      k++;
    }
    printf("\n");
  }

  matriz(n, m, ma, x, l);
  
  return 0;
}
void matriz(int n, int m, int ma[n][m], int x, int l) {
  int i, j, aux = 0;

    for (j = 0; j < m; j++) {
      if (ma[l - 1][j] == x) {
        aux = 1;
        break;
      } 
    }
  if (aux == 1) {
  printf("\nO valor %d esta na linha %d da matriz.\n",x, l);
  } else {
    printf("\nO valor %d nao esta na linha %d sa matriz.\n",x, l);
  }
}
