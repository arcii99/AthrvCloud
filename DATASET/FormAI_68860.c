//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
// Get ready to generate some prime numbers, woohoo!

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    // Check if num is divisible by any number from 2 to num/2
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    printf("How many prime numbers do you want to generate? ");
    scanf("%d", &n);

    int count = 0;
    int i = 2;

    printf("Generating prime numbers...\n");

    while (count < n) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }

    printf("\nDone generating %d prime numbers!\n", n);

    return 0;
}