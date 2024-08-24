/*  Lista de Exercícios (String):

    É usada para calcular o comprimento de uma string,
    ou seja, o número de caracteres antes do caractere 
    nulo ('\0') que marca o final da string.
*/

int my_strlen(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

/*  
    A função strcpy é usada para copiar uma string de 
    origem para um destino.
*/

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; // Adiciona o caractere nulo no final da string de destino
}

/*  
    A função strcat é usada para concatenar (juntar) 
    duas strings, anexando a segunda no final da primeira.
*/

void my_strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; // Adiciona o caractere nulo no final da string concatenada
}

/*
    A função strcmp é usada para comparar duas strings.
    Ela retorna um valor negativo se a primeira string 
    for "menor" (em ordem lexicográfica) que a segunda, 
    um valor positivo se for "maior" e 0 se forem iguais.
*/

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0; // As strings são iguais
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}