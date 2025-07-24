//FormAI DATASET v1.0 Category: Educational ; Style: Donald Knuth
// This program calculates the first n prime numbers
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num);

int main() {
    int n;
    printf("Enter the number of prime numbers to calculate: ");
    scanf("%d", &n);
    printf("\nThe first %d prime numbers are:\n", n);
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    return 0;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}