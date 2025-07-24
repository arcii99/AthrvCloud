//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>

int isPrime(int n);

int main() {
    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    // Loop through all integers from 2 to n
    for (i = 2; i <= n; i++) {
        // Check if current number is a prime
        if (isPrime(i)) {
            printf("%d ", i);
            flag = 1;
        }
    }

    // If no prime is found between 2 and n
    if (!flag) {
        printf("None");
    }

    return 0;
}

// Function to check if a number is prime
int isPrime(int n) {
    int i;
    // Iterate from 2 to n/2 to check if there are any factors
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0; // Not a prime
        }
    }
    return 1; // A prime
}