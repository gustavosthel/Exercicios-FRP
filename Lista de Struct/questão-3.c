/*
	FAETERJ-Rio
	FPR - 2024/1 - Turmas Manhã e Noite
	Data: 13/04/2024 (aula extra)
	
	Lista de Exercícios VII
	
	Questão 03:
	Considere a existência de um vetor de structs com quant posições, onde cada uma 
	destas armazena os seguintes dados sobre os funcionários de uma empresa: 
	matricula (int), nome (string), gênero (char) e salário (float). Pede-se 
	uma função que, dado um gênero, desloque todos os funcionários deste gênero 
	para o início do vetor (e, consequentemente, os funcionários do outro gênero 
	ficarão ao final do conjunto).
*/

#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
  int matricula;
  char nome[30];
  char genero;
  float salario;
} TFuncionario;

//protótipos das funções
void organizarPorGenero (TFuncionario vetor[], int quantidade, char genero);

void preencherVetor (TFuncionario vetor[], int quantidade);
void exibirVetor (TFuncionario vetor[], int quantidade);

//main
void main() {
  //declaração de funcionários
  TFuncionario func[5];

  //preenchendo o vetor (para testar, foi preenchido "na mão", com 5 structs)
  preencherVetor (func, 5);

  //exibindo o vetor antes da organização
  printf ("ANTES:\n");
  exibirVetor (func, 5);

  //chamando a função (para testar, definiu genero = F
  organizarPorGenero (func, 5, 'F');

  //exibindo o vetor após a organização
  printf ("\n\nDEPOIS:\n");
  exibirVetor (func, 5);
}

//implementação das funções
void organizarPorGenero (TFuncionario vetor[], int quantidade, char genero) {
  //declaração de variáveis
  int i = 0, j = quantidade-1;
  TFuncionario aux;

  //percorrendo o vetor
  while (i < j) {
    //verificando se a posição 'i' armazena uma pessoa do gênero especificado
    if (vetor[i].genero == genero) {
      i++;
    } else {
      //verificando se a posição 'j' armazena uma pessoa diferente do gênero especificado
      if (vetor[j].genero != genero) {
        j--;
      } else { //se chegou aqui, a troca é necessária
        //trocando as posições
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;

        i++;
        j--;
      }
    }
  }	
}

void preencherVetor (TFuncionario vetor[], int quantidade) {
  //1ª posição
  vetor[0].matricula = 123;
  strcpy (vetor[0].nome, "JOAO");
  vetor[0].genero = 'M';
  vetor[0].salario = 10000;

  //2ª posição
  vetor[1].matricula = 234;
  strcpy (vetor[1].nome, "MARIA");
  vetor[1].genero = 'F';
  vetor[1].salario = 12000;

  //3ª posição
  vetor[2].matricula = 345;
  strcpy (vetor[2].nome, "PEDRO");
  vetor[2].genero = 'M';
  vetor[2].salario = 5000;

  //4ª posição
  vetor[3].matricula = 456;
  strcpy (vetor[3].nome, "ANA");
  vetor[3].genero = 'F';
  vetor[3].salario = 7000;

  //5ª posição
  vetor[4].matricula = 567;
  strcpy (vetor[4].nome, "CARLA");
  vetor[4].genero = 'F';
  vetor[4].salario = 6000;
}

void exibirVetor (TFuncionario vetor[], int quantidade) {
  //declaração de variáveis
  int i;

  //percorrendo o vetor
  for (i=0;i<quantidade;i++)
  {
    printf ("\nMatricula: %d\n", vetor[i].matricula);
    printf ("Nome: %s\n", vetor[i].nome);
    printf ("Genero: %s\n", (vetor[i].genero=='F'?"Feminino":"Masculino"));
    printf ("Salario: R$ %.2f\n", vetor[i].salario);
  }	
}