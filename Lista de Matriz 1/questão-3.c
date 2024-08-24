/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 03/04/2024
   
   Lista de Exercícios IV (Matrizes):
   
   QUESTÃO 03:
	Desenvolver uma função que gere uma matriz Mnxn, nos moldes do exemplo 
	apresentado a seguir (que consiste em uma matriz de ordem 5)

							1	2	3	4	5	
							2	3	4	5	6	
							3	4	5	6	7	
							4	5	6	7	8	
							5	6	7	8	9	
*/

#include <stdio.h>

void matriz(int m[5][5]);

int main(void) {
  int m[5][5];

  printf("Matriz:\n");
  matriz(m);
  return 0;
}
void matriz(int m[5][5]) {
  int i, j, k = 1;
  for (i = 0; i < 5; i++) {
    k = i + 1;
    for (j = 0; j < 5; j++) {
      m[i][j] = k;
      printf("%d ", m[i][j]);
      k++;
    }
    printf("\n");
  }
}