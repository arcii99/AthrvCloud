//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include <stdio.h>

//Function to check if a number is prime
int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

//Function to generate prime numbers up to a given limit
void generatePrimes(int limit) {
    int primes[limit];
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes[count] = i;
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
}

int main() {
    int limit;
    printf("Enter the limit up to which you want prime numbers: ");
    scanf("%d", &limit);
    printf("The prime numbers up to %d are: ", limit);
    generatePrimes(limit);
    return 0;
}