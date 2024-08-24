/*  Lista de Exercícios VIII (Recursividade)

    Questão 07:
    Desenvolver uma função recursiva que, dado
    um vetor V com quant números inteiros,
    determine se seus elementos estão dispostos
    de maneira a representar uma progressão
    aritmética.
*/

#include <stdio.h>

#define tam 5

int descobrindoPA(int v[], int tamanho, int aux);

int main(void) {
    int v[] = {2, 4, 6, 8, 10};
    

    if (descobrindoPA(v, tam, 0) == 1) {
        printf("e PA");
    } else {
        printf("Nao e uma PA");
    }

    return 0;
}

int descobrindoPA(int v[], int tamanho, int aux) {
    int razao = 0;

    if (aux >= tamanho) {
        return 1;
    } else {
        razao = v[aux + 1] - v[aux];
        if (v[aux + 1] - v[aux] != razao) {
            return 0;
        } else {
            return descobrindoPA(v, tamanho, aux + 1);
        }
    }
}