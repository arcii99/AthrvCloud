//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimes(int n) {
    int count = 0;
    printf("The prime numbers up to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal count: %d\n", count);
}

int main() {
    int N;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter a positive integer: ");
    scanf("%d", &N);
    printPrimes(N);
    return 0;
}