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
void SoaresCountingSort(int * A, int n, int min, int max){
	int j=max-min+1;
	int * C = (int *)calloc(j, sizeof(int));
	if(!C){
		fprintf(stderr, "Memory Allocation Error.");
		exit(1);
	}

	i = n-1;
	do{
		C[A[i]-min]++;
		i--;
	}
	while(i>=0);

	i = n-1;
	j--;
	do{
		if(C[j]>0){
			A[i] = j+min;
			C[j]--;
			j++;
			i--;
		}
			j--;
	}
	while(i>=0);
	
	free(C);
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
			
			SoaresCountingSort(A, n, min, max);
			
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