//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    int i, j, n, flag;

    printf("Enter the maximum number to generate primes up to: ");
    scanf("%d", &n);

    printf("Generating prime numbers from 2 to %d...\n\n", n);

    // Loop through numbers 2 to n
    for(i=2; i<=n; i++) {
        flag = 1;
        // Check if i is prime
        for(j=2; j<=i/2; j++) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }
        // If i is prime, print it
        if (flag == 1) {
            printf("%d\n", i);
        }
    }

    printf("\nDone!\n");

    return 0;
}