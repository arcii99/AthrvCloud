//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdio.h>

// Check if num is a prime number
int is_prime(int num) {
    // If num is less than 2, it cannot be prime
    if(num < 2)
        return 0;
    
    // Check if num is divisible by any number less than itself
    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("\n");
    
    int primes[n]; // Initialize an array to store the prime numbers
    int count = 0; // Initialize a count variable to keep track of the number of primes found
    int current_num = 2; // Initialize the current number to check for primeness
    
    // Loop until we've found n prime numbers
    while(count < n) {
        if(is_prime(current_num)) {
            primes[count] = current_num; // Add the current number to the primes array
            count++; // Increment the count of primes found
        }
        current_num++; // Check the next number for primeness
    }
    
    // Print out the list of prime numbers
    printf("List of the first %d prime numbers:\n", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    
    printf("\n");
    return 0;
}