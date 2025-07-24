//FormAI DATASET v1.0 Category: Scientific ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime or not
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// main function
int main() {
    int n, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int prime[n];
    int count = 0;
    for (int i = 1; count < n; i++) {
        if (isPrime(i)) {
            prime[count] = i;
            count++;
        }
    }

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += prime[i] * prime[i + 1];
    }

    printf("The sum of the product of consecutive prime numbers up to %d is %d\n", n, total);

    return 0;
}