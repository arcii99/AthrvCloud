//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a large prime number to use in testing prime numbers
#define PRIME 9999991

// Function to check if a number is prime
int is_prime(int n) {
    if(n <= 1) {
        return 0;
    }
    if(n == 2 || n == 3) {
        return 1;
    }
    if(n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    int i = 5;
    int w = 2;
    while(i*i <= n) {
        if(n % i == 0) {
            return 0;
        }
        i += w;
        w = 6 - w;
    }
    return 1;
}

// Function to calculate the sum of all primes up to a given number
unsigned long long sum_of_primes(int n) {
    unsigned long long sum = 0;
    for(int i = 2; i <= n; i++) {
        if(is_prime(i)) {
            sum += i;
        }
    }
    return sum;
}

// Main function to test the sum_of_primes function
int main() {
    // Create a large array of integers to test the scalability of the function
    int arr[PRIME];

    // Fill the array with random numbers between 1 and 100
    for(int i = 0; i < PRIME; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Calculate the sum of all primes up to 1000000
    unsigned long long sum = sum_of_primes(1000000);

    // Print the result
    printf("The sum of all primes up to 1000000 is %llu\n", sum);

    return 0;
}