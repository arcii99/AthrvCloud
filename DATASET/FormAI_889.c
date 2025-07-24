//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: lively
#include <stdio.h>

int main() {
	int n, i, count, j, prime;
	
	printf("Enter the value of n: ");
	scanf("%d", &n);
	
	printf("The prime numbers between 2 and %d are:\n", n);
	
	// loop through numbers 2 to n
	for (i = 2; i <= n; i++) {
		count = 0;
		
		// loop through numbers 1 to i
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		
		// check if prime
		if (count == 2) {
			printf("%d ", i);
			prime = 1;
		}
	}
	
	// check if no primes found
	if (!prime) {
		printf("None");
	}
	
	return 0;
}