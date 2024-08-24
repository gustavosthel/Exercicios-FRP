/*  Lista de Exercícios VIII (Recursividade)

    Questão 06:
    Desenvolver uma função recursiva que, dada
    uma string, exiba-a invertida.
*/

#include <stdio.h>
#include <string.h>

void inverter(char s[], int inicio, int fim);

int main(void) {
    char s[] = "preco";

    inverter(s, 0, strlen(s) - 1);
}

void inverter(char s[], int inicio, int fim) {
    int aux = 0;

    if (inicio >= fim) {
        printf("%s", s);
    } else {
        aux = s[inicio];
        s[inicio] = s[fim];
        s[fim] = aux;
        return inverter(s, inicio + 1, fim - 1);
    }
}