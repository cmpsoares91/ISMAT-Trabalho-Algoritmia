#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define compGT(a,b) (a > b)
#define DEBUG 0

void SoaresCountingSortOPT(int * array, int n, int min, int max){
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
void SoaresCountingSort2(int * array, int n, int min, int max){
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
}
void radixsort(int *a, int n, int max){
	int i, b[max], m = 0, exp = 1;
	for (i = 0; i < n; i++){
		if (a[i] > m)
			m = a[i];
	}
 
	while (m / exp > 0){
		int bucket[10] ={0,0,0,0,0,0,0,0,0,0};
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
void bubbleSort(int * item, int n){
	int a, b, t;
	/* now, sort them using a bubble sort */
	for(a = 1; a < n; ++a){
		for(b = n-1; b >= a; --b) {
			/* compare adjacent elements */
			if(item[ b - 1] > item[ b ]) {
			/* exchange elements */
			t = item[ b - 1];
			item[ b - 1] = item[ b ];
			item[ b ] = t;
			}
		}
	}
}
void shellSort(int * a, int n) {
    int h, i, j;
    int t;

    /* compute largest increment */
    h = 1;
    if (n < 14)
        h = 1;
    else if (sizeof(int) == 2 && n > 29524)
        h = 3280;
    else {
        while (h < n) h = 3*h + 1;
        h /= 3;
        h /= 3;
    }

    while (h > 0) {

        /* sort-by-insertion in increments of h */
        for (i = 0 + h; i <= n; i++) {
            t = a[i];
            for (j = i-h; j >= 0 && compGT(a[j], t); j -= h)
                a[j+h] = a[j];
            a[j+h] = t;
        }

        /* compute next increment */
        h /= 3;
    }
}
int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}
int * CountingSort(int * array, int n, int min, int max){
	int i, k, j=0;
	int * B = 0;
	int * C = 0;
	
	if(min < 0){
		fprintf(stderr, "The counting sort algorithm only works with positive integers.");
		exit(1);
	}
	B = (int *)calloc(n, sizeof(int));
	if(!B){
		fprintf(stderr, "CountingSort.B: Memory Allocation Error.");
		exit(1);
	}
	k =	(max-min+1);
	C = (int *)calloc(k, sizeof(int));
	if(!C){
		fprintf(stderr, "CountingSort.C: Memory Allocation Error.");
		exit(1);
	}
	for(i=0;i<n;i++){
		C[array[i]]++;
	}
	for(i=1;i<k;i++){
		C[i] += C[i-1];
	}
	for(j=(n-1);j>=0;j--){
		if(B[C[array[j]]-1] == array[j]){
			C[array[j]]--;
			j++;
		}
		else{
			B[C[array[j]]-1] = array[j];
		}
	}
	array = B;
	free(B);
	free(C);
	
	return array;
}
void swap(int A[], int i, int Idx){
	int temp;
	
	temp=A[i];
	A[i]=A[Idx];
	A[Idx]=temp;

}
void selectionSort(int * A, int n){
	int i, j, Idx;
	
	for(i=0;i<n-1;i++){
		Idx=i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[Idx])
				Idx=j;
		}
		swap(A, i, Idx);
	}
}
void insertionSort(int * A, int n){
	int i, j, key;
	
	for(i=1;i<n;i++){
		key = *(A+i);
		j = i-1;
		while((j>=0) && (*(A+j)>key)){
			*(A+j+1) = *(A+j);
			j--;
		}
		*(A+j+1) = key;
	}
}
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
		fprintf(stderr, "genArray: Memory Allocation Error.");
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
		fprintf(stderr, "SoaresCountingSort: Memory Allocation Error.");
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
	int * array = 0;
	int control, n, min, max, iTest, trials, select;
	clock_t start, stop;
	double t = 0.0;
	
	printf("\n\nHow many trials do you want to performe? ");
	scanf(" %d", &trials);
	for(select=1;select<=10;select++){
		for(iTest=0;iTest<trials;iTest++){
			/*printf("Trial %d:\n", (iTest+1));
			 Start timer */
			start = clock();
		
			if((argc == 4) && (atoi(argv[1]) > 0)){
				if(iTest+1){
					n = atoi(argv[1]);
					min = atoi(argv[2]);
					max = atoi(argv[3]);
				}
				if((n == 1) || (min == max)){
					control = 1;
				}
				else{
					array = genArray(n, min, max);
					#ifdef DEBUG
					fprintArray(array, n, "antes.txt");
					#endif
					
					switch(select){
						case 1: {
							SoaresCountingSort(array, n, min, max);
							break;
						}
						case 2: {
							qsort(array, n, sizeof(int), compare);
							break;
						}
						case 3: {
							insertionSort(array, n);
							break;
						}
						case 4: {
							selectionSort(array, n);
							break;
						}
						case 5: {
							array = CountingSort(array, n, min, max);
							break;
						}
						case 6: {
							shellSort(array, n);
						}
						case 7: {
							bubbleSort(array, n);
						}
						case 8: {
							radixsort(array, n, max);
						}
						case 9: {
							SoaresCountingSort2(array, n, min, max);
							break;
						}
						case 10: {
							SoaresCountingSortOPT(array, n, min, max);
							break;
						}
					}
					
					#ifdef DEBUG
					fprintArray(array, n, "depois.txt");
					#endif
					control = ControlSort(array, n);
				}	
				/*if(control)
					printf("O array esta ordenado.\n");
				else
					printf("O array nao esta ordenado.\n");*/
			}
			else
				fprintf(stderr, "Parameters Error.");
	
			free(array);
		
			/* Stop timer */
			stop = clock();
			t += (double) (stop-start)/CLOCKS_PER_SEC;
		}
		printf("\n\nSelct = %d. Average run time (%d trials): %f secs\nTotal run time: %f secs", select, trials, (t/trials), t);
	}
	
	return 0;
}