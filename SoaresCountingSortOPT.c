#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0

void fprintArray(int * A, int n, char * fname){
	/*For Debugging*/
	int i;
	FILE * fp = fopen(fname, "w");
	fprintf(fp, "Array Gerado:\n\n%10s | %10s", "Idx", "A[Idx]");
	for(i=0;i<n;i++){
		fprintf(fp, "\n%10d | %10d", i, A[i]);
	}
	fclose(fp);
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
	int i, j=max-min+1;
	int * counter = (int *)calloc(j, sizeof(int));
	if(!counter){
		fprintf(stderr, "Memory Allocation Error.");
		exit(1);
	}

	i = n-1;
	do{
		counter[array[i]-min]++;
		i--;
	}
	while(i>=0);

	i = n-1;
	j--;
	do{
		if(counter[j]>0){
			array[i] = j+min;
			counter[j]--;
			j++;
			i--;
		}
			j--;
	}
	while(i>=0);
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
	int * array = 0;
	int control, n, min, max;
	clock_t start, stop;
	double t = 0.0;

	/* Start timer */
	start = clock();
	
	if((argc == 4) && (atoi(argv[1]) > 0)){
		n = atoi(argv[1]);
		min = atoi(argv[2]);
		max = atoi(argv[3]);
		if((n == 1) || (min == max)){
			control = 1;
		}
		else{
			array = genArray(n, min, max);
			
			#ifdef DEBUG
			fprintArray(array, n, "antes.txt");
			#endif
			
			SoaresCountingSort(array, n, min, max);
			
			#ifdef DEBUG
			fprintArray(array, n, "depois.txt");
			#endif
			
			control = ControlSort(array, n);
			}
		if(control)
			printf("O array esta ordenado.");
		else
			printf("O array nao está ordenado.");
	}
	else
		fprintf(stderr, "Parameters Error.");
		
	free(array);
	
	/* Stop timer */
	stop = clock();
	t = (double) (stop-start)/CLOCKS_PER_SEC;

	printf("\n\nRun time: %f sec\n", t);
		
	return 0;
}