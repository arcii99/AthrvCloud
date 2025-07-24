//FormAI DATASET v1.0 Category: Scientific ; Style: portable
/* This program calculates the sum of all prime numbers within a given range */
#include <stdio.h>
#include <stdbool.h>

// Checks if a number is prime or not
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int start, end, sum = 0;
    printf("Enter starting number: ");
    scanf("%d", &start);
    printf("Enter ending number: ");
    scanf("%d", &end);

    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    printf("The sum of all prime numbers between %d and %d is: %d", start, end, sum);
    return 0;
}