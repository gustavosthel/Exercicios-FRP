/*
    Considere a existência de um vetor de structs
    com quant posições, onde cada uma destas
    armazena os seguintes dados sobre um grupo
    de pessoas: nome (string), gênero (char) e
    idade (int). Pede-se uma função que determine
    se os elementos deste vetor estão ordenados e
    retorne 1, caso estejam ordenados, e 0, caso
    contrário.
    Observação: o vetor será considerado ordenado se
    estiver organizado crescentemente em função da
    idade. Porém, no caso de pessoas com a mesma
    idade, estas devem estar ordenadas crescentemente
    pelo nome.
*/

#include <stdio.h>
#include <string.h>

#define tam 3

typedef struct {
  char nome[30]; 
  char genero[30];
  int idade;
} TPessoa;

int definindoOrdenado(TPessoa p[tam], int quantidade);
void preencherVetor (TPessoa p[], int quantidade);

int main(void) {
  TPessoa vetor[tam];
  
  preencherVetor(vetor, tam);

  printf("Descobrindo se o vetor esta ordenado por idade ou nome\n\n");
  if (definindoOrdenado(vetor, tam) == 1) {
    printf("O vetor esta ordenado por idade ou nome!\n");
  } else {
    printf("O vetor nao esta ordenado por idade ou nome!\n");
  }
}

int definindoOrdenado(TPessoa p[tam], int quantidade) {
  int i;

  for (i = 0; i < quantidade - 1; i++) {
    if (p[i].idade < p[i+1].idade) {
      return  1;
    } else if(p[i].idade == p[i+1].idade){
      if (strcmp(p[i].nome, p[i+1].nome) < 0) {
        return 0;
      }
    }
  }
}

void preencherVetor (TPessoa p[], int quantidade) {
  //Pessoa 1
  strcpy (p[0].nome, "JOAO");
  strcpy (p[0].genero, "MASCULINO");
  p[0].idade = 20;

  //Pessoa 2
  strcpy (p[1].nome, "MARIA");
  strcpy (p[1].genero, "FEMININO");
  p[1].idade = 30;
  
  //Pessoa 3
  strcpy (p[2].nome, "PAULO");
  strcpy (p[2].genero, "MASCULINO");
  p[2].idade = 40;
} 