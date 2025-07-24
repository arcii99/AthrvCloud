//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime
bool isPrime(int num) {
    // 1 and 0 are not prime numbers
    if (num == 0 || num == 1) {
        return false;
    }
    
    // check if the number is divisible by any number from 2 to its square root
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

// function to generate a list of prime numbers up to a given limit
void generatePrimes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    
    // check each number from 2 to the limit if it is prime and print it if it is
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

int main() {
    int limit;
    
    printf("Enter the upper limit for prime numbers: ");
    scanf("%d", &limit);
    
    // generate the list of prime numbers up to the given limit
    generatePrimes(limit);
    
    return 0;
}