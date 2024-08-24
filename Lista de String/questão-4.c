/* Lista de Exercícios VI (Strings):
   
   Questão 04:
   Desenvolver uma função que, dada uma string s, crie uma substring que 
   inicie na posição p de s  e contenha n caracteres.
   
   Observações: 
   	i) se p e/ou n forem inválidos, a substring será vazia; 
    ii) se s não possuir n caracteres além de p, a substring a ser criada 
	    começará em p e terminará no final de s.	
*/

#include <stdio.h>
#include <string.h>

void substring (char s[], int p, int n, char subs[]);

void main(void){
	//declaração de variáveis
	char s[20], sub[20];
	int posicao, quantidade;
	
	//lendo uma string para s
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (s);
	
	//lendo a posição
	printf ("\nEntre com a posicao: ");
	scanf ("%d", &posicao);
	
	//lendo a quantidade de caracteres da substring
	printf ("\nEntre com a quantidade de caracteres da substring: ");
	scanf ("%d", &quantidade);
	
	//chamando a função
	substring (s, posicao, quantidade, sub);
	
	//exibindo a substring criada
	printf ("\n\nSubstring: %s", sub);	
}

//implementação das funções
void substring (char s[], int p, int n, char subs[]) {
	int i, j;
	
	//validando 'p' e 'n'
	if ((p < 0) || (p >= strlen(s)) || (n <= 0)) {
		subs[0] = '\0';    //ou:   strcpy (subs, "");
	} else {
		for (i = p, j = 0; (s[i]) && (j < n); i++, j++) {
			subs[j] = s[i];
		}
		
		subs[j] = '\0';
	}
}