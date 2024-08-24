/* Trabalho de FPR Tabela hash (Listas Encadeadas):

    Este trabalho consiste na implementação de uma
    tabela hash simples, com as seguintes características:

    a. A tabela hash será composta por 10 listas
    encadeadas simples (na prática, um vetor de
    TLista, com tamanho igual a 10);
    b. Os elementos de cada uma das listas não estão
    dispostos de forma ordenada (crescente ou
    decrescente). Ou seja, não há critério algum
    de ordenação de seus elementos;
    c. Elementos repetidos são proibidos nesta
    tabela hash.

    Devem ser desenvolvidas as mesmas operações
    (funções) trabalhadas nas aulas para a implementação
    de lista encadeada, a saber:
     Inserção de um novo valor;
     Remoção de determinado elemento;
     Alteração de um número por outro;
     Busca de um elemento na tabela;
     Exibição dos elementos: esta operação poderá
    ser executada de duas maneiras, por escolha
    do usuário – exibir os elementos de uma das
    listas (informando o seu número) ou de toda a
    tabela.

    Nome: Gustavo Costa Sthel
    Matricula: 23204708360053
*/

#include <stdio.h>
#include <stdlib.h>

#define tamanho_tabela 10

typedef struct No {
  int valor;
  struct No *prox;
} TNo;

typedef TNo *TLista;

typedef struct {
  TLista table[tamanho_tabela];
} TTabela;


int inserir(TTabela *tabela, int numero);
int remover(TTabela *tabela, int numero);
TLista buscar(TTabela *tabela, int numero);
int altera(TTabela *tabela, int numero, int novo_numero);
void exibir_tabela(TTabela *tabela);
void exibir(TTabela *tabela, int lista);
int descobriIndice(int valor);
void inicializa_tabela(TTabela *tabela);
int menu();

int main() {
  TTabela tabela;
  int num1, num2, opcao;
  inicializa_tabela(&tabela);

  do {
    opcao = menu();

    switch(opcao) {
      case 1: 
        printf("Digiite o numero a ser inserido: ");
        scanf("%d", &num1);

        if (inserir(&tabela, num1)) {
          printf("Numero %d inserido com sucesso!\n\n", num1);
        } else {
          printf("Erro: Elemento %d ja existe na tabela\n\n", num1);
        }
        break;

      case 2:
        printf("Digete o numero a ser removido: ");
        scanf("%d", &num1);

        if (remover(&tabela, num1)) {
          printf("Numero %d removido com sucesso!\n\n", num1);
        } else {
          printf("Erro: Elemento %d não existe na lista!\n\n", num1);
        } 
        break;

      case 3:
        printf("Digite o numero a ser alterado: ");
        scanf("%d", &num1);
        printf("Digite o novo numero: ");
        scanf("%d", &num2);

        if (altera(&tabela, num1, num2)) {
          printf("Numero %d alterado com sucesso!\n\n", num1);
        } else {
          printf("Erro ao alterar o numero %d!\n\n", num1);
        }
        break;

      case 4:
        printf("Digite o numero a ser buscado: ");
        scanf("%d", &num1);

        if (buscar(&tabela, num1)) {
          printf("Numero %d encontrado na tabela!\n\n", num1);
        } else {
          printf("Numero %d nao encontrado na tabela!\n\n", num1);
        }
        break;

      case 5:
        exibir_tabela(&tabela);
        break;

      case 6:
        printf("Digite o numero da lista a ser exibida: ");
        scanf("%d", &num1);

        if (num1 >= 0 && num1 < tamanho_tabela) {
            exibir(&tabela, num1);
        } else {
            printf("Numero de lista invalido!\n\n");
        }
        break;

      case 7:
        printf("Programa finalizado!\n");
        break;

      default:
        printf("Opcao invalida!\n");
    }
    
    printf("Pressione enter para continuar...");
    getchar(); 
    getchar(); 

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    
  } while (opcao != 7);
  return 0;
}

int inserir(TTabela *tabela, int numero) {
  int indice = descobriIndice(numero);

  if (buscar(tabela, numero)) {
    return 0;
  } else {
    TLista novo = (TLista)malloc(sizeof(TNo));
    if (!novo) {
      return 0;
    } else {
      novo->valor = numero;
      novo->prox = tabela->table[indice];
      tabela->table[indice] = novo;
    }
    return 1;
  }
}

int remover(TTabela *tabela, int numero) {
  int indice = descobriIndice(numero);
  TLista anterior = tabela->table[indice];
  TLista proximo;

  if (anterior) {
    if (anterior->valor == numero) {
      tabela->table[indice] = anterior->prox;
      free(anterior);
      return 1;
    } else {
      proximo = anterior->prox;
      while (proximo) {
        if (proximo->valor == numero) {
          anterior->prox = proximo->prox;
          free(proximo);
          return 1;
        }
        anterior = anterior->prox;
        proximo = proximo->prox;
      }
    }
  } 
  return 0;
}

int altera(TTabela *tabela, int numero, int novo_numero) {
  TLista atual = buscar(tabela, numero);

  if (atual) {
    // para evitar uma alteração desnecessaria ele ja retona 1
    // evitando percorre a lista duas vezes
    if (atual->valor == novo_numero) {
      return 1;
    } else {
      if (inserir(tabela, novo_numero)) {
          if (remover(tabela, numero)) {
              return 1;
          }
        remover(tabela, novo_numero);
        return 0;
      }
    }
  } 
  return 0;
}

TLista buscar(TTabela *tabela, int numero) {
  int indice = descobriIndice(numero);
  TLista atual = tabela->table[indice];

  while (atual) {
    if (atual->valor == numero) {
      return atual;
    } 
    atual = atual->prox;
  }
  return NULL;
}

void exibir_tabela(TTabela *tabela) {
  for (int i = 0; i < tamanho_tabela; i++) {
    printf("Índice %d: ", i);
    TLista atual = tabela->table[i];
    while (atual) {
      printf("%d -> ", atual->valor);
      atual = atual->prox;
    }
    printf("\n");
  }
  printf("\n");
}

void exibir(TTabela *tabela, int lista) {
  int indice = descobriIndice(lista);

  printf("\nIndice %d: ", indice);
  TLista atual = tabela->table[indice];
  while (atual) {
    printf("%d -> ", atual->valor);
    atual = atual->prox;
  }
  printf("\n\n");
}

int descobriIndice(int valor) { 
  return valor % tamanho_tabela; 
}

void inicializa_tabela(TTabela *tabela) {
  for (int i = 0; i < tamanho_tabela; i++) {
    tabela->table[i] = NULL;
  }
}

int menu() {
  int opcao;

  printf("1 - Inserir\n");
  printf("2 - Remover\n");
  printf("3 - Alterar\n");
  printf("4 - Buscar\n");
  printf("5 - Exibir tabela\n");
  printf("6 - Exibir lista\n");
  printf("7 - Sair\n");
  printf("\n");

  printf("Escolher opção: ");
  scanf("%d", &opcao);
  printf("\n");

  return opcao;
}