/* Lista de Exercícios V (Matrizes):
   
   Questão 05:
   Desenvolver uma função que receba duas matrizes de 
   inteiros, ambas de ordem 10, com as seguintes 
   características:
		a.	M1: matriz contendo números inteiros quaisquer;
		b.	M2: matriz contendo apenas os valores 0 ou 1. 

   Desenvolver uma função que a partir destas matrizes gere 
   a matriz M3, também de ordem 10, cujos elementos são 
   definidos da seguinte forma:

		M2ij = 0	=>	M3ij = M1ij
		M2ij = 1 	=>	M3ij = soma dos elementos da linha 
		                i com os da coluna j da matriz.
*/

#include <stdio.h>
#include <stdlib.h>

#define x 4
#define y 4

void imprimirMatriz(int m[x][y]);
int gerandom3(int m1[x][y], int m2[x][y], int m3[x][y]);
int somaMatriz(int m1[x][y], int i, int j);

int main(void) {

  int m1[x][y] = {
      {1, 3, 5, 4},
      {5, 7, 1, 3},
      {3, 8, 7, 5},
      {1, 3, 5, 4},
  };

  int m2[x][y] = {
      {0, 1, 0, 1},
      {1, 0, 1, 0},
      {0, 1, 0, 1},
      {1, 0, 1, 0},
  };

  int m3[x][y];

  gerandom3(m1, m2, m3);
  printf("Matriz 3:\n\n");
  imprimirMatriz(m3);

  return 0;
}
int gerandom3(int m1[x][y], int m2[x][y], int m3[x][y]) {
  int i, j, soma = 0;

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (m2[i][j] == 0) {
        m3[i][j] = m1[i][j];
      } else {
        m3[i][j] = somaMatriz(m1, i, j);
      }
    }
  }
}

void imprimirMatriz(int m[x][y]) {
  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

int somaMatriz(int m1[x][y], int i, int j) {
  int k, soma = 0;

  for (k = 0; k < y; k++) {
    soma += m1[i][k];
  }

  for (k = 0; k < x; k++) {
    soma += m1[k][j];
  }

  return soma;
}