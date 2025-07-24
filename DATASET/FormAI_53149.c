//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>

int isPrime(int num);

int main() {
    int n, i;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("\nThe first %d prime numbers are:\n", n);

    // Two is the first prime number
    if (n >= 1) {
        printf("%d\n", 2);
    }

    // Check for prime numbers starting with 3
    for (i = 3; i <= n * 2; i += 2) {
        if (isPrime(i)) {
            printf("%d\n", i);
            n--;
        }
        if (n == 0) {
            break;
        }
    }

    return 0;
}

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    
    // Check if the number is divisible by 2
    if (num % 2 == 0) {
        return 0;
    }

    // Check for odd factors
    for (i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}