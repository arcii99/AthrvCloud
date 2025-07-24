//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>

// Function to check if a number is prime or not
int is_prime(int n) {
    // Return false for n less than or equal to 1
    if (n <= 1) {
        return 0;
    }

    // Loop through numbers from 2 to n-1 and check if it's divisible
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    // If no number divides n, then it's prime
    return 1;
}

int main() {
    int n;

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are:\n", n);

    int i = 2;
    int count = 0;

    // Loop through numbers until we find n primes
    while (count < n) {
        // Check if the current number is prime
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }

    return 0;
}