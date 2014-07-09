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
	int i;
	int * array = 0;

	srand(time(0));
	
	array = (int *)malloc(n * sizeof (int));
	if(!array){
		fprintf(stderr, "Memory Allocation Error.");
		exit(1);
	}
	else{
		for(i=0;i<n;i++){
			array[i]=((rand()%(max-(min-1)))+min);
		}
	}
	
	return array;
}
void SoaresCountingSort(int * array, int n, int min, int max){
	int i, j=0;
	int * counter = (int *)calloc((max-min+1), sizeof(int));
	if(!counter){
		fprintf(stderr, "Memory Allocation Error.");
		exit(1);
	}
	for(i=0;i<n;i++){
		counter[array[i]-min]++;
	}
	for(i=0;i<n;i++){
		if(counter[j]>0){
			array[i] = j+min;
			counter[j]--;
		}
		else{
			j++;
			i--;
		}
	}
	
	free(counter);
}
int ControlSort(int * array, int n){
	int i, flag = 1;
	for(i=1; i<n; i++){
		if((*(array+i)) < (*(array+i-1))){
			flag = 0;
			i = n;
			}
	}
	
	return flag;
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