//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime or not
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// function to generate prime numbers up to n
void primeGenerator(int n) {
    printf("Prime numbers up to %d are: ", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    primeGenerator(n);
    printf("\n");
    return 0;
}