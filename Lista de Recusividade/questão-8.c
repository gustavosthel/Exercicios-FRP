/*  Lista de Exercícios VIII (Recursividade)

    Questão 08:
    Implementar uma função recursiva que,
    dados uma string str e um caracter ch,
    remova de str todas as ocorrências de ch,
    retornando o total de remoções realizadas.
*/

#include <stdio.h>
#include <string.h>

int excluindoCaracter(char str[], char ch, int aux);

int main(void) {

    char str[] = "projeto";

    printf("%d ", excluindoCaracter(str, "t", 0)); 

}

int excluindoCaracter(char *str, char ch, int aux) {
  int cont = 0;

  if (aux <= strlen(str) - 1) {
    if (str[aux] == ch) {
      cont++;
      memmove(str + aux, str + aux + 1, strlen(str) - aux - 1);
      cont += excluindoCaracter(str, ch, aux);
    } 
      excluindoCaracter(str, ch, aux + 1);
  } else {
    return cont;
  }

  return cont;
}