#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i;

int isnum(char * str){
	
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
int * genArray(int n, int min, int max){
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
/*funcao quicksort*/
int quicksort (int *array, int size) {
    if (size < 2)
        return 0;
    int pivot = array[size / 2];	/*pivot, é o numero que está no meio do array */
    int *begin = array;		/*apontador da esq.*/
    int *end = array + size - 1;	/*apontador da direita*/

	/*funçao divide o array em dois e verifica começando pelas duas pontas*/
    while (begin <= end){	/* em quanto o valor da esquerda for inferior ao valor da direita*/
        while (*begin < pivot)	/* em quanto o valor da esquerda for inferior ao pivot, muda o valor l, para o valor seguinte */
            begin++;
        while (*end > pivot)	/* em quanto o valor da direita for inferior ao pivot, muda o valor l, para o valor anterior */
            end--;
        if (begin <= end){	/* se o pivot for inferior ou igual ao valor do apontador da direita, troca o????????????????????*/

            /*talvez em vex de isto colocar a funcao swap*/
            int temp = *begin;
            *begin++ = *end;
            *end-- = temp;
        }
    }
    quicksort(array, end - array + 1);/*reinicia a função e altera o valor tamanho  ????????????? */
    quicksort(begin, array + size - begin);/*reinicia a função ???????????*/

	return 1;
}

int ControlSort(int * A, int n){
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
	
	n = atoi(argv[1]);
	min = atoi(argv[2]);
	max = atoi(argv[3]);

	if((argc == 4) && isnum(argv[1]) && isnum(argv[2]) && isnum(argv[3]) && (n > 0) && (min < max) && (min >= -n) && (max <= n)){
		if((n == 1) || (min == max)){
			control = 1;
		}
		else{
			A = genArray(n, min, max);
			
			quicksort(A, n);
			
			control = ControlSort(A, n);
		}
			
		if(control)
			printf("O array esta ordenado.");
		else
			printf("O array nao está ordenado.");
	}
	else
		fprintf(stderr, "Parameters Error.");
		
	free(A);
	
	return 0;
}