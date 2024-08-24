/*  Lista de Exercícios VII
	
	Questão 01:
	Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de 
	structs contendo as seguintes informações, para cada veículo: placa, modelo, 
	marca, cor, quilometragem, ano modelo/fabricação (deve ser um struct), valor 
	e tipo (usado ou 0 km, conforme o valor do campo quilometragem). 
	
	Pede-se a declaração de uma variável que represente o estoque de veículos 
	da loja, incluindo todas as declarações de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
	i.   Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 
	     (inclusive), com valor não superior a x reais;
	ii.	 Reajustar os valores de todos os carros 0 km, considerando um aumento de p %;
	iii. Retirar do estoque um determinado veículo, dada a sua placa.
*/

#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
  int fabricacao;
  int modelo;
} TAno;

typedef struct {
  char placa[10];
  char modelo[20];
  char marca[20];
  char cor[20];
  float quilometragem;
  TAno ano;
  float valor;
  char tipo[10];
} TCarro;

//protótipos das funções
int  filtrarCarros (TCarro ag[], int quantidade, char modelo[], int anoInicial, int anoFinal, float valorLimite);
void reajustar0KM (TCarro ag[], int quantidade, float taxaAumento);
int  removerCarro (TCarro ag[], int *quantidade, char placa[]);

void exibirDadosCarro (TCarro carro);
void preencherVetor (TCarro agencia[]);
void exibirTodosCarros (TCarro agencia[], int quantidade);

//main
void main() {
  //declaração de variáveis
  TCarro agencia[TAM];
  int quantCarros = TAM;

  //preenchendo o vetor para que as demais funções possam ser testadas
  preencherVetor (agencia);

  //exibindo os carros que atenderem aos filtros definidos

  //Chamada 1
  printf ("Chamada 1 (exibindo carros por filtro):\n");
  if (filtrarCarros (agencia, quantCarros, "HB20", 2015, 2020, 38000) == 0) {
    printf ("\nNenhum carro atende aos filtros apresentados!\n\n");
  }

  //Chamada 2
  printf ("Chamada 2 (exibindo carros por filtro):\n");
  if (filtrarCarros (agencia, quantCarros, "CRETA", 2015, 2020, 38000) == 0) {
    printf ("\nNenhum carro atende aos filtros apresentados!\n\n");
  }

  //chamando a função que reajustará os carros 0km
  reajustar0KM (agencia, quantCarros, 2.5);

  //exibindo os carros após o reajuste
  printf ("\n\nExibindo os carros apos o reajuste:\n");
  exibirTodosCarros (agencia, quantCarros);

  //Chamada 1
  printf ("Chamada 1 (removendo carro do estoque):\n");
  if (removerCarro (agencia, &quantCarros, "XYZ 1234") == 1) {
    printf ("\n\tCarro removido com sucesso!\n");
    exibirTodosCarros (agencia, quantCarros);
  } else {
    printf ("\n\tPlaca não localizada!\n\n");
  }

  //Chamada 2
  printf ("Chamada 2 (remvendo carro do estoque):\n");
  if (removerCarro (agencia, &quantCarros, "CDE 3456") == 1) {
    printf ("\n\tCarro removido com sucesso!\n");
    exibirTodosCarros (agencia, quantCarros);
  } else {
    printf ("\n\tPlaca não localizada!\n\n");
  }
}

//implementação das funções
int  filtrarCarros (TCarro ag[], int quantidade, char modelo[], int anoInicial, int anoFinal, float valorLimite) {
  //declaração de variáveis
  int i, cont = 0;

  //percorrendo todos os carros da agência
  for (i=0;i<quantidade;i++) {
    //aplicando os filtros
    if ((strcmp(modelo,ag[i].modelo) == 0) &&   //verificando o modelo
        ((ag[i].ano.fabricacao >= anoInicial) && (ag[i].ano.fabricacao <= anoFinal)) &&
        (ag[i].valor <= valorLimite)) {
      exibirDadosCarro (ag[i]);

      cont++;
    }
  }

  //retornando a quantidade de carros que atenderam aos filtros
  return cont;
}

void exibirDadosCarro (TCarro carro) {
  printf ("Placa: %s\n", carro.placa);
  printf ("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
  printf ("Cor: %s\n", carro.cor);
  printf ("Km: %.1f\n", carro.quilometragem);
  printf ("Ano: %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
  printf ("Valor: R$ %.2f\n", carro.valor);
  printf ("Tipo: %s\n\n", carro.tipo);
}

void exibirTodosCarros (TCarro agencia[], int quantidade) {
  //declaração de variáveis
  int i;

  //percorrendo o vetor que representa a agência de carros
  for (i=0;i<quantidade;i++)
  {
    exibirDadosCarro (agencia[i]);
  }
}

void reajustar0KM (TCarro ag[], int quantidade, float taxaAumento) {
  //declaração de variáveis
  int i;

  //percorrendo todos os carros da agência
  for (i=0;i<quantidade;i++) {
    //verificando se é um carro 0 km
    if (ag[i].quilometragem == 0) {
      ag[i].valor *= (1 + taxaAumento/100);
    }
  }
}

int  removerCarro (TCarro ag[], int *quantidade, char placa[]) {
  //declaração de variáveis
  int i;

  //percorrendo todos os carros da agência
  for (i=0;i<*quantidade;i++) {
    //verificando se o carro com a placa passada como parâmetro foi encontrado
    if (strcmp(placa,ag[i].placa) == 0) {
      //deslocando o último carro do vetor para a posição 'i'
      ag[i] = ag[(*quantidade)-1];

      (*quantidade)--;

      return 1;
    }
  }	

  return 0;
}

void preencherVetor (TCarro agencia[]) {
  //1º carro
  strcpy (agencia[0].placa, "ABC 1234");
  strcpy (agencia[0].modelo, "HB20");
  strcpy (agencia[0].marca, "HYUNDAI");
  strcpy (agencia[0].cor, "PRATA");
  agencia[0].quilometragem = 20000;
  agencia[0].ano.modelo = 2016;
  agencia[0].ano.fabricacao = 2015;
  agencia[0].valor = 25000;
  strcpy (agencia[0].tipo, "USADO");	

  //2º carro
  strcpy (agencia[1].placa, "BCD 2345");
  strcpy (agencia[1].modelo, "CIVIC");
  strcpy (agencia[1].marca, "HONDA");
  strcpy (agencia[1].cor, "BRANCA");
  agencia[1].quilometragem = 0;
  agencia[1].ano.modelo = 2022;
  agencia[1].ano.fabricacao = 2022;
  agencia[1].valor = 90000;
  strcpy (agencia[1].tipo, "0KM");	

  //3º carro
  strcpy (agencia[2].placa, "CDE 3456");
  strcpy (agencia[2].modelo, "HB20");
  strcpy (agencia[2].marca, "HYUNDAI");
  strcpy (agencia[2].cor, "PRETA");
  agencia[2].quilometragem = 45000;
  agencia[2].ano.modelo = 2017;
  agencia[2].ano.fabricacao = 2017;
  agencia[2].valor = 35000;
  strcpy (agencia[2].tipo, "USADO");	

  //4º carro
  strcpy (agencia[3].placa, "EFG 4567");
  strcpy (agencia[3].modelo, "HB20");
  strcpy (agencia[3].marca, "HYUNDAI");
  strcpy (agencia[3].cor, "AZUL");
  agencia[3].quilometragem = 58000;
  agencia[3].ano.modelo = 2019;
  agencia[3].ano.fabricacao = 2018;
  agencia[3].valor = 40000;
  strcpy (agencia[3].tipo, "USADO");	

  //5º carro
  strcpy (agencia[4].placa, "FGH 5678");
  strcpy (agencia[4].modelo, "ECOSPORT");
  strcpy (agencia[4].marca, "FORD");
  strcpy (agencia[4].cor, "VERDE");
  agencia[4].quilometragem = 0;
  agencia[4].ano.modelo = 2022;
  agencia[4].ano.fabricacao = 2022;
  agencia[4].valor = 85000;
  strcpy (agencia[4].tipo, "0KM");	
}