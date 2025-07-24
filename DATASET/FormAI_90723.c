//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>

// Function to check if a given number is prime or not
int isPrime(int num) {
    int i;
    for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0; // not prime
        }
    }
    return 1; // prime
}

int main() {
    int n, i;

    printf("Enter the number of prime numbers: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are: ", n);

    for (i = 2; n > 0; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
            --n;
        }
    }

    return 0;
}