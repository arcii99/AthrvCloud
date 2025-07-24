//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine if a given number is prime
int is_prime(int num) {
    for(int i=2; i<=num/2; i++) {
        if(num%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Initialize variables
    int num1, num2, num3, sum, product;
    int prime1, prime2, prime3;

    // Generate random numbers between 1 and 10
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    num3 = rand() % 10 + 1;

    sum = num1 + num2 + num3; // Calculate sum of random numbers
    product = num1 * num2 * num3; // Calculate product of random numbers

    // Determine if each random number is prime
    prime1 = is_prime(num1);
    prime2 = is_prime(num2);
    prime3 = is_prime(num3);

    // Print out the numbers and whether or not they are prime
    printf("Number 1: %d (", num1);
    if(prime1) {
        printf("prime)");
    } else {
        printf("not prime)");
    }
    printf("\nNumber 2: %d (", num2);
    if(prime2) {
        printf("prime)");
    } else {
        printf("not prime)");
    }
    printf("\nNumber 3: %d (", num3);
    if(prime3) {
        printf("prime)");
    } else {
        printf("not prime)");
    }

    // Print out the sum and product
    printf("\n\nSum: %d", sum);
    printf("\nProduct: %d", product);

    return 0;
}