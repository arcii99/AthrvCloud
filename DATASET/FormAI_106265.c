//FormAI DATASET v1.0 Category: System boot optimizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
bool isPrime(int n);
int getPrime(int n);
void optimizeBoot();

int main() {
    printf("Welcome to the Post-Apocalyptic C System Boot Optimizer!\n");
    optimizeBoot();
    printf("Boot optimization complete. System is now ready to use.\n");
    return 0;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n == 2 || n == 3 || n == 5)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Function to get the nth prime number
int getPrime(int n) {
    int count = 0;
    int i = 2;
    while (count < n) {
        if (isPrime(i))
            count++;
        if (count == n)
            return i;
        i++;
    }
    return -1;
}

// Function to optimize the system boot process
void optimizeBoot() {
    int num_primes;
    char buffer[100];
    printf("Please enter the number of prime numbers to generate: ");
    fgets(buffer, 100, stdin);
    num_primes = atoi(buffer);
    while (num_primes <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        fgets(buffer, 100, stdin);
        num_primes = atoi(buffer);
    }
    int prime = getPrime(num_primes);
    int i;
    for (i = 0; i < prime; i++) {
        printf("Accessing system file #%d...\n", i);
    }
    printf("Initializing system modules...\n");
    printf("Optimizing boot process...\n");
    int delay = 10;
    for (i = 0; i < prime; i++) {
        printf("System module #%d optimized\n", i);
        printf("Waiting %d seconds...\n", delay);
        sleep(delay);
    }
    printf("Boot optimization successful!\n");
}