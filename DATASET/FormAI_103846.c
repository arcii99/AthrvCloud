//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Welcome to the Peaceful Data Mining Program.\n");

	// Declare and initialize data arrays
	int data1[10] = {4, 7, 3, 1, 9, 5, 2, 8, 6, 0};
	int data2[10] = {5, 8, 2, 0, 6, 4, 3, 1, 7, 9};
	int results[10];

	// Perform data mining operation
	for(int i=0; i<10; i++) {
		results[i] = data1[i] + data2[i];
	}

	// Print out results
	printf("Results:\n");
	for(int i=0; i<10; i++) {
		printf("%d\n", results[i]);
	}

	printf("Thank you for using the Peaceful Data Mining Program.\n");
	return 0;
}