
/* Lista de Exercícios V (Matrizes):
   
   Questão 02:
   Dada uma matriz MLxC, onde L e C são constantes, 
   desenvolver uma função que "troque" os elementos de 
   duas colunas c1 e c2, respeitadas as seguintes regras:

	a. A troca só será possível se as colunas c1 e c2 
	   existirem na matriz. Caso existam, a troca será 
	   realizada e o valor 1 retornado pela função; por 
	   outro lado, 0 será retornado se uma ou as duas 
	   colunas forem inválidas;
	b. Após a troca, a coluna c2 conterá exatamente os 
	   elementos originais da coluna c1, na mesma ordem. 
	   Porém, os valores da coluna c1 serão os originais da 
	   c2, na ordem inversa.   
*/

#include <stdio.h>

#define x 6
#define y 5

void imprimirMatriz(int matriz[x][y]);
void imprimirMatrizTransposta(int matriz[x][y], int c1, int c2);

int main() {
  int i, j, k = 1;
  
  int matriz[x][y] = {
      {1, 3, 5, 7, 9},
      {4, 6, 5, 8, 0},
      {3, 4, 5, 7, 8},
      {5, 9, 1, 2, 3},
      {7, 1, 5, 3, 5},
      {4, 0, 2, 1, 5}
  };

  int c1 = 1, c2 = 3;
  
  printf("Matriz original:\n");
  imprimirMatriz(matriz);
  printf("\n");
  printf("Matriz transposta:\n");
  imprimirMatrizTransposta(matriz, c1, c2);
  return 0;
}
void imprimirMatrizTransposta(int matriz[x][y], int c1, int c2) {
  int i, aux;

  for (i = 0; i < x; i++) {
    aux = matriz[i][c1];
    matriz[i][c1] = matriz[i][c2];
    matriz[i][c2] = aux;
  }
  
  for (i = 0; i < x / 2; i++) {
      aux = matriz[i][c1];
      matriz[i][c1] = matriz[x - 1 - i][c1];
      matriz[x - 1 - i][c1] = aux;
  }
  
  imprimirMatriz(matriz);
}
void imprimirMatriz(int matriz[x][y]) {
  int i, j;
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}