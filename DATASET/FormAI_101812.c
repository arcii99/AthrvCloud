//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {  // 1 is neither prime nor composite
        return false;
    }
    
    // check from 2 to n-1
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;  // not a prime number
        }
    }
    
    return true;  // if none of the above returned false, then the number is prime
}

void generatePrimeNumbers(int n) {
    int count = 0;
    
    for (int i = 2; count < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
}

int main() {
    int n;
    
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    
    printf("The first %d prime numbers are:\n", n);
    generatePrimeNumbers(n);
    
    return 0;
}