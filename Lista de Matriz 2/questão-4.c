/* Lista de Exercícios V (Matrizes):
   
   Questão 04:
   Dada uma matriz MLxC, onde L e C são constantes, 
   desenvolver uma função que verifique se os elementos da 
   matriz estão ordenados de forma crescente. Para isto, as 
   seguintes regras devem ser atendidas:
   
   a. Os elementos de cada linha devem estar ordenados 
      crescentemente (ou seja, cada elemento será maior 
	  ou igual àquele da mesma linha, porém da coluna 
	  anterior - caso exista);
   b. O primeiro elemento de cada linha deve ser maior ou 
      igual ao último da linha anterior (caso exista).

   Caso a matriz M atenda aos critérios definidos, o valor 1 
   deverá ser retornado pela função; caso contrário, 0.
*/

#include <stdio.h>

#define x 3
#define y 3

void imprimirMatriz(int m[x][y]);
int verificandoCresente(int m[x][y]);

int main(void) {
  int i, j;

  int m[x][y] = {
      {1, 3, 5},
      {4, 6, 7},
      {3, 4, 5},
  };

  imprimirMatriz(m);
  if (verificandoCresente(m)) {
    printf("\nA matriz é cresente");
  } else {
    printf("\nA matriz não é cresente");
  }
  
  return 0;
}
int verificandoCresente(int m[x][y]) {
  int i, j, vdd = 0;

  for (i = 0; i < x; i++) {
    for (j = 1; j <= y - 1; j++) {
      if (m[i][j - 1] < m[i][j]) {
        vdd = 1;
      } else {
        return 0;
      }
    }
  }

  for (i = 1; i < m; i++) {
		if (m[i][0] < m[i-1][y-1]) {
			return 0;
		}
	}
  return 1;
}
void imprimirMatriz(int m[x][y]) {
  int i, j;
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}