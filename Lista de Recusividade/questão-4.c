/*  Lista de Exercícios VIII (Recursividade)  

    Dada uma string s, desenvolver uma função
    recursiva que determine se s é ou não um
    palíndromo.
*/

#include <stdio.h>
#include <string.h>

int palindromo(char s[], int inicio, int fim);

int main(void) {
   char s[] = "arara";

   if (palindromo(s, 0, strlen(s) - 1) == 1) {
    printf("E um palindromo");
   } else {
    printf("Nao e um palindromo");
   }
}

int palindromo(char s[], int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    } else {
        if (s[inicio] != s[fim]) {
            return 0;
        } else {
            return palindromo (s, inicio + 1, fim - 1);
        }
    }
}