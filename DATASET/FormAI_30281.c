//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>

// function to check if a number is prime or not
int isPrime(int n) {
    int i;
    for(i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to generate and print prime numbers
void generatePrimes(int n) {
    int i, count = 0;
    printf("\nPrime numbers between 1 and %d: ", n);
    for(i = 2; i <= n; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal prime numbers generated: %d\n", count);
}

int main() {
    int n;
    printf("Enter a number to generate prime numbers: ");
    scanf("%d", &n);
    generatePrimes(n);
    return 0;
}