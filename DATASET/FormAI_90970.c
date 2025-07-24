//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFibonacci(int n){
	int first = 0, second = 1, next, i;
	
	//prints the first two numbers
	printf("Fibonacci Series: ");
	printf("%d %d ", first, second);
	
	for(i=2; i<n; ++i){
		next = first + second;
		printf("%d ",next);
		first = second;
		second = next;
	}
}

int main(){
	int n;
	clock_t start, end;
	
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	
	start = clock(); //starting time
	
	printFibonacci(n);
	
	end = clock(); //ending time
	float time_taken = ((double)end - start) / CLOCKS_PER_SEC;
	printf("\nTime taken by Fibonacci function is %f seconds", time_taken);
	
	return 0;
}