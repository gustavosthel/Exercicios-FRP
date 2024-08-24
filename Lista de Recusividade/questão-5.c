/*  Lista de Exercícios VIII (Recursividade)

    Desenvolver uma função recursiva que
    determine o número de caracteres comuns
    entre duas strings s1 e s2.
*/

#include <stdio.h>
#include <string.h>

int numerosIguais(char s1[], char s2[], int aux1, int aux2);

int main(void) {
    int result;
    char s1[] = "teste";
    char s2[] = "trsvtafasf";

    result = numerosIguais(s1, s2, 0, 0);
    printf("%d", result);


    return 0;
}

int numerosIguais(char s1[], char s2[], int aux1, int aux2) {
    int cont = 0;

    if (s1[aux1] != '\0' || s2[aux2] != '\0') {
        if (s1[aux1] == s2[aux2]) {
            cont++;
        }
        return cont + numerosIguais(s1, s2, aux1 + 1, aux2 + 1);
    }
    return cont;
}