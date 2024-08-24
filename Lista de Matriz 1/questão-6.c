/* Lista de Exercícios IV (Matrizes):
   
   QUESTÃO 06:
   Considere uma loja que mantém em uma matriz o total 
   vendido por cada funcionário pelos diversos meses do 
   ano. Ou seja, uma matriz de 12 linhas (uma por mês) e 
   10 colunas (10 funcionários). Pede-se o desenvolvimento 
   de uma função para cada item abaixo:
   
   a. Calcular o total vendido durante o ano;
   b. Dado um mês fornecido pelo usuário, determinar o total 
      vendido nesse mês;
   c. Dado um funcionário fornecido pelo usuário, determinar 
      o total vendido por ele durante o ano;
   d. Determinar o mês com maior índice de vendas;
   e. Determinar o funcionário que menos vendeu durante o ano.
*/

#include <stdio.h>

#define X 12
#define Y 10

int somarTotal(int m[X][Y]);
int somaMes(int m[X][Y], int mes);
int somafuncionario(int m[X][Y], int funci);
int maiorVendasMes(int m[X][Y]);
int FunciMenosVendas(int m[X][Y]);

int main(void) {
  int m[X][Y], k = 1, i, j, mes, funci;
  
  printf("\nMatriz:\n");
  for (i = 0; i < X; i++) {
    for (j = 0; j < Y; j++) {
      m[i][j] = k;
      printf("%d ", m[i][j]);
      k++;
    }
    printf("\n");
  }
  printf("\n");
  printf("Informe o mes para saber o tota vendido: ");
  scanf("%d", &mes);

  printf("Informe o funcionario para saber o tota vendido no ano: ");
  scanf("%d", &funci);

  printf("Total vendido no ano: %d\n", somarTotal(m));
  printf("Total vendido no mes: %d\n", somaMes(m, mes));
  printf("Total vendido pelo funcionario: %d\n", somafuncionario(m,funci));
  printf("Maior venda no mes: %d\n", maiorVendasMes(m));
  printf("Funcionario com menos vendas no mes: %d\n", FunciMenosVendas(m));
  return 0;
}
int somarTotal(int m[X][Y]) {
  int soma = 0, i, j;
  for (i = 0; i < X; i++) {
    for (j = 0; j < Y; j++) {
      soma += m[i][j];
    }
  }
  return soma;
}
int somaMes(int m[X][Y], int mes) {
  int i, j, soma = 0;

  for (i = 0; i < X; i++) {
    if (i == mes - 1) {
      for (j = 0; j < Y; j++) {
        soma += m[i][j]; 
      }
    }
  }
  return soma;
}
int somafuncionario(int m[X][Y], int funci) {
  int i, j, soma = 0;

  for (j = 0; j < Y; j++) {
    if (j == funci - 1) {
      for (i = 0; i < X; i++) {
        soma += m[i][j]; 
      }
    }
  }
  return soma;
}
int maiorVendasMes(int m[X][Y]) {
  int i, j, maior = 0, soma;

  for (i = 0; i < X; i++) {
    soma = 0;
    for (j = 0; j < Y; j++) {
      soma += m[i][j];
    }
    if (soma > maior) {
      maior = soma;
    }
  }
  return maior;
}
int FunciMenosVendas(int m[X][Y]) {
  int i, j, menor = 10000, soma;

  for (j = 0; j < Y; j++) {
    soma = 0;
    for (i = 0; i < X; i++) {
      soma += m[i][j];
    }
    if (soma < menor) {
      menor = soma;
    }
  }
  return menor;
}