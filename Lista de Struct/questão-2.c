/*
	FAETERJ-Rio
	FPR - 2024/1 - Turmas Manhã e Noite
	Data: 13/04/2024 (aula extra)
	
	Lista de Exercícios VII
	
	Questão 02: 
	Suponha a existência de um vetor de tamanho TAM, cada posição armazenando o nome 
	da pessoa e a sua data de aniversário (representada por um struct do tipo TData, 
	contendo os campos dia e mes). Pede-se o desenvolvimento das seguintes funções:
 	
	 	- Determinar a quantidade de pessoas que fazem aniversário no mês M;
		- Exibir os nomes de todas pessoas que fazem aniversário entre as datas 
		  d1 e d2, ambas do tipo TData.
*/

#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
  int dia,
      mes;
} TData;

typedef struct {
  char nome[30];
  TData dataNascimento;
} TPessoa;

//protótipos das funções
int  aniversariantesMes (TPessoa vetPessoas[], int quantidade, int mes);
void exibirAniversariantes (TPessoa vetPessoas[], int quantidade, TData data1, TData data2);

int aniversariantePeriodo (TData data, TData dataInicio, TData dataFim);
void preencherVetor (TPessoa vetPessoas[], int quantidade); 

//main
void main() {
  //declaração de variáveis
  TPessoa vetor[5];
  TData d1, d2;

  //preenchendo as varovaeis 'TData'
  d1.dia = 10;
  d1.mes = 6;

  d2.dia = 20;
  d2.mes = 10;

  //preenchendo o vetor
  preencherVetor (vetor, 5);

  //chamando a função 'aniversariantesMes'
  printf ("Quantidade de aniversariantes de Abril: %d\n\n", aniversariantesMes (vetor, 5, 4));

  exibirAniversariantes (vetor, 5, d1, d2);
}

//implementação das funções
int  aniversariantesMes (TPessoa vetPessoas[], int quantidade, int mes) {
  //declaração de variáveis
  int i, cont = 0;

  //percorrendo o vetor
  for (i=0;i<quantidade;i++) {
    //verificando se a pessoa da posição 'i' faz aniversário em 'mes'
    if (vetPessoas[i].dataNascimento.mes == mes) {
      cont++;
    }
  }

  return cont;
}

void exibirAniversariantes (TPessoa vetPessoas[], int quantidade, TData data1, TData data2) {
  //declaração de variáveis
  int i;

  //percorrendo o vetor
  for (i=0;i<quantidade;i++) {
    //verificando se a pessoa da posição 'i' faz aniversário no período definido
    //por 'data1' e 'data2'
    if (aniversariantePeriodo (vetPessoas[i].dataNascimento, data1, data2) == 1) {
      printf ("Nome: %s (%d/%d)\n", vetPessoas[i].nome, 
      vetPessoas[i].dataNascimento.dia, vetPessoas[i].dataNascimento.mes);
    }
  }	
}

int aniversariantePeriodo (TData data, TData dataInicio, TData dataFim) {
  //declaração de variáveis
  int dataEmDias, dataInicioEmDias, dataFimEmDias;

  //convertendo para dias as datas passadas por parâmetro
  dataEmDias = data.dia + (data.mes*30);
  dataInicioEmDias = dataInicio.dia + (dataInicio.mes*30);
  dataFimEmDias = dataFim.dia + (dataFim.mes*30);

  //verificando se 'data' está no intervalo especificado
  if ((dataEmDias >= dataInicioEmDias) && (dataEmDias <= dataFimEmDias)) {
    return 1;
  } else {
    return 0;
  }
}

void preencherVetor (TPessoa vetPessoas[], int quantidade) {
  //Pessoa 1
  strcpy (vetPessoas[0].nome, "JOAO");
  vetPessoas[0].dataNascimento.dia = 5;
  vetPessoas[0].dataNascimento.mes = 8;

  //Pessoa 2
  strcpy (vetPessoas[1].nome, "MARIA");
  vetPessoas[1].dataNascimento.dia = 20;
  vetPessoas[1].dataNascimento.mes = 4;

  //Pessoa 3
  strcpy (vetPessoas[2].nome, "PAULO");
  vetPessoas[2].dataNascimento.dia = 30;
  vetPessoas[2].dataNascimento.mes = 4;

  //Pessoa 4
  strcpy (vetPessoas[3].nome, "ANA");
  vetPessoas[3].dataNascimento.dia = 15;
  vetPessoas[3].dataNascimento.mes = 10;

  //Pessoa 5
  strcpy (vetPessoas[4].nome, "CARLA");
  vetPessoas[4].dataNascimento.dia = 10;
  vetPessoas[4].dataNascimento.mes = 6;
}