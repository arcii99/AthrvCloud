//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are:\n", n);

    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    return 0;
}