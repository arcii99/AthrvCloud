//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>

// Function to check whether a number is prime or not
int isPrime(int n) {
    if (n <= 1) 
        return 0;
    else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
}

// Function to generate prime numbers within a given range
void generatePrimes(int start, int end) {
    printf("The prime numbers between %d and %d are:\n", start, end);

    // Iterate through the range and check if each number is prime
    for (int i = start; i <= end; i++) {
        if (isPrime(i))
            printf("%d\n", i);
    }
}

int main() {   
    int start, end;

    // Take user input for the range of numbers
    printf("Enter the range of numbers to generate prime numbers:\n");
    printf("Start: ");
    scanf("%d", &start);
    printf("End: ");
    scanf("%d", &end);

    // Call the prime number generator function
    generatePrimes(start, end);

    return 0;
}