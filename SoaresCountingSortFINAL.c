/*************************************************
*Trabalho Pr�tico de Avalia��o n� 1 de Algoritmia*
**************************************************
* Autor:              Carlos Soares, n� 21103408 *
*                                                *
* Curso:                        Eng. Inform�tica *
* Universidade:                  ISMAT, Portim�o *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i; /*Vari�vel declarada globalemente para diminuir a quantidade de declara��es de vari�veis auxiliar feitas*/

int isnum(char * str){ /*Fun��o que verifica se a string � um n�mero inteiro devolve 1 se sim e 0 se n�o*/

	if((*str != '-') && (*str != '0') && (*str != '1') && (*str != '2') && (*str != '3') && (*str != '4') && (*str != '5') && (*str != '6') && (*str != '7') && (*str != '8') && (*str != '9'))
		return 0;
	str++;

	while(*str != '\0'){
		if((*str != '0') && (*str != '1') && (*str != '2') && (*str != '3') && (*str != '4') && (*str != '5') && (*str != '6') && (*str != '7') && (*str != '8') && (*str != '9'))
			return 0;
		str++;
	}
	
	return 1;
}
int * genArray(int n, int min, int max){ /*Gero um array com n itens de valores aleatorios entre min e max*/
	int * A = 0;

	srand(time(0));
	
	A = (int *)malloc(n * sizeof (int));
	if(!A){
		fprintf(stderr, "Memory Allocation Error.");
		exit(1);
	}
	else{
		i = n-1;
		do{
			A[i]=((rand()%(max-min+1)))+min;
			i--;
		}while(i >= 0);
	}
	
	return A;
}
void SoaresCountingSort(int * A, int n, int min, int max){ /*O algoritmo de ordena��o*/
	int j=max-min+1;			/*Variavel que nos ir� dar o n�mero de elementos diferentes s�o poss�veis*/
	int * C = (int *)calloc(j, sizeof(int));	/*Array contador com j elementos, inicializado a zero, calloc evita a necessidade criar o primeiro ciclo do algoritmo*/
	if(!C){
		fprintf(stderr, "Memory Allocation Error.");
		exit(1);
	}

	i = n-1;
	do{
		C[A[i]-min]++;
		i--;
	}
	while(i>=0);	/*Ciclo para contar a quantidade de elementos existentes de cada valor diferente*/

	i = n-1;
	j--;
	do{
		if(C[j]>0){	/*Verifica��o se "ainda" existem elementos a que corresponde o actual j para colocar*/
			A[i] = j+min;
			C[j]--;
			j++;
			i--;
		}
			j--;
	}
	while(i>=0);	/*O ciclo que escreve por cima do array inicial os valores ordenados*/
	
	free(C);	/*Libera a memoria utilizada pelo array auxiliar*/
}
int ControlSort(int * A, int n){ /*Fun��o que verifica se um array est� ordenado de forma n�o decrescente, utiliza um simples ciclo que faz a compara��o de cada elemento com o proximo*/
	int f = 1;

	i = n-1;
	do{
		if((*(A+i)) < (*(A+i-1))){
			i = f = 0;
			}
		i--;
	}while(i>=1); 
	
	return f;
}
int main(int argc, char * argv[]){
	int * A = 0;
	int control, n, min, max;
	
	n = atoi(argv[1]);	/*Para converter as strings em inteiros*/
	min = atoi(argv[2]);
	max = atoi(argv[3]);

	if((argc == 4) && isnum(argv[1]) && isnum(argv[2]) && isnum(argv[3]) && (n > 0) && (min < max) && (min >= -n) && (max <= n)){ /*Verifica��o de que se os parametros introduzidos far�o sentido*/
		if((n == 1) || (min == max)){ /*Verifica��o de se os resultados estar�o evidente ordenados*/
			control = 1;
		}
		else{
			A = genArray(n, min, max); /*Gera-se o array em que A ir� receber o respectivo apontador*/

			SoaresCountingSort(A, n, min, max); /*O array � ordenado*/

			control = ControlSort(A, n);	/*Controla-se se o array A esta ordenado, ou seja, se a ordena��o foi bem sucedida*/
		}
			
		if(control)	/*Passa a informa��o ao utilizador de que se o array est� ordenado ou n�o.*/
			printf("O array esta ordenado.");
		else
			printf("O array nao est� ordenado.");
	}
	else
		fprintf(stderr, "Parameters Error.");
		
	free(A);	/*Libera a memoria utilizada pelo array A*/
	
	return 0;
}