/*
    Questão 05:
    O histórico de um aluno é representado por um
    vetor de structs onde cada posição armazena o
    código da disciplina cursada, semestre e ano
    que a cumpriu e a média final na disciplina.
    Implementar uma função que exiba o histórico
    do aluno com o seguinte formato:

    NomeDisciplina1 (código1) MédiaDisciplina1
    NomeDisciplina2 (código2) MédiaDisciplina2
    NomeDisciplinaN (códigoN) MédiaDisciplinaN
    Coeficiente de rendimento: CR

    Observações:
    1. Para obter os dados da disciplina, um outro
    vetor de structs deve ser consultado. Este,
    por sua vez, armazena para cada disciplina
    do curso as seguintes informações: código,
    nome e número de créditos;

    2. O coeficiente de rendimento consiste em
    uma média ponderada de todos os graus
    atribuídos às disciplinas cursadas, onde os
    pesos são representados pelo número de
    créditos da disciplina;

    3. Todos os dados em negrito apresentados no
    formato do histórico devem ser obtidos a
    partir dos vetores.
*/

#include <stdio.h>
#include <string.h>

#define tam 3

typedef struct {
  int codigo; 
  char nome[30];
  int creditos;
} TDiciplina;

typedef struct { 
  int ano;
  int semestre;
  float media;
  TDiciplina diciplina;
} THistorico;

float calcularCr(THistorico historico[], int quantidade);
void preencherVetor (THistorico historico[], int quantidade);
void imprimirHistorico(THistorico historico[], int quantidade);

int main(void) {
  THistorico historico[tam];
  int i;

  preencherVetor(historico, tam);

  imprimirHistorico(historico, tam);

  printf("\nCoeficiente de Rendimento: %.2f", calcularCr(historico, tam));
  
  return 0;
}

float calcularCr(THistorico historico[], int quantidade) {
  float cr, somaNotasPonderadas = 0, somaCreditos  = 0;
  int i;

  for (i = 0; i < quantidade; i++) {
    somaNotasPonderadas += historico[i].media * historico[i].diciplina.creditos;
    somaCreditos += historico[i].diciplina.creditos;
  }

  if (somaCreditos > 0) {
    cr = somaNotasPonderadas / somaCreditos;
  }

  return cr;
}

void imprimirHistorico(THistorico historico[], int quantidade) {
  int i;

  for(i = 0; i < quantidade; i++) {
    printf("%s (Codigo:%d): %.2f\n", historico[i].diciplina.nome, historico[i].diciplina.codigo, historico[i].media);
  }
}

void preencherVetor (THistorico historico[], int quantidade) {
  //historico 1
  historico[0].ano = 2020;
  historico[0].semestre = 1;
  historico[0].media = 7.5;
  historico[0].diciplina.codigo = 1345;
  strcpy(historico[0].diciplina.nome, "Algoritmos");
  historico[0].diciplina.creditos = 4;

  //historico 2
  historico[1].ano = 2020;
  historico[1].semestre = 1;
  historico[1].media = 7.7;
  historico[1].diciplina.codigo = 1271;
  strcpy(historico[1].diciplina.nome, "Desenvolvimento Web");
  historico[1].diciplina.creditos = 2;

  //historico 3
  historico[2].ano = 2020;
  historico[2].semestre = 1;
  historico[2].media = 5.5;
  historico[2].diciplina.codigo = 4269;
  strcpy(historico[2].diciplina.nome, "Calculo I");
  historico[2].diciplina.creditos = 2;
} 