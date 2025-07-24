//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i, is_prime;
    
    printf("PRIME NUMBER GENERATOR\n");

    // Prompt user for the number of primes to generate 
    printf("Enter the number of primes to generate: ");
    scanf("%d", &num);

    // Print the first prime number, 2
    printf("2 ");

    // Loop through the odd numbers starting at 3 and check if they are prime
    for (i = 3; num > 1; i = i + 2) {
        is_prime = isPrime(i);
        if (is_prime) {
            printf("%d ", i);
            num--;
        }
    }
    printf("\n");

    return 0;
}