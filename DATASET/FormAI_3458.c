//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <math.h>

// Function to check whether the number is prime
int isPrime(int num) {

    if (num < 2)
        return 0;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Function to generate prime numbers
int generatePrimes(int num) {
    int count = 0, i = 2;
    while (count < num) {
        if (isPrime(i)) {
            printf("%d, ", i);
            count++;
        }
        i++;
    }
    return 0;
}

int main() {
    int num;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num);
    
    printf("\nGenerating %d prime numbers...\n\n", num);
    generatePrimes(num);

    printf("\n");
    return 0;
}