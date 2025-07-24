//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int n) {
    int count = 0; // Keep track of how many prime numbers we've found
    int current = 2; // Start at 2, the first prime number

    printf("The first %d prime numbers are:\n", n);

    while(count < n) { // Keep generating prime numbers until we have enough
        if(isPrime(current)) {
            printf("%d ", current);
            count++;
        }
        current++;
    }
}

int main() {
    int n;

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    generatePrimes(n);

    return 0;
}