//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

int main() {
	int size;
	printf("Enter the size of the pattern: ");
	scanf("%d", &size);

	// Printing the first half of the pattern
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size-i; j++) {
			printf("*");
		}
		for(int k = 0; k < i; k++) {
			printf(" ");
		}
		for(int l = 0; l < i; l++) {
			printf(" ");
		}
		for(int m = 0; m < size-i; m++) {
			printf("*");
		}
		printf("\n");
	}

	// Printing the second half of the pattern
	for(int i = 0; i < size-1; i++) {
		for(int j = 0; j <= i+1; j++) {
			printf("*");
		}
		for(int k = 0; k < size-i-2; k++) {
			printf(" ");
		}
		for(int l = 0; l < size-i-2; l++) {
			printf(" ");
		}
		for(int m = 0; m <= i+1; m++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}