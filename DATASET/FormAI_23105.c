//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>

int is_prime(int num) {
    if (num < 2) { // Check for single digit numbers
        return 0;
    }
    for (int i=2; i<num; i++) { // Loop through each number less than num
        if (num % i == 0) { // Check if num is divisible by i
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n); // Read number of primes to generate from user
    int count = 0; // Initialize a variable to count the number of primes generated
    int num = 2; // Start with 2 since it's the first prime number
    printf("The first %d prime numbers are: ", n);
    while (count < n) { // Loop until n prime numbers are generated
        if (is_prime(num)) { // Check if current number is prime
            printf("%d ", num); // Print current number
            count++; // Increment prime count
        }
        num++; // Move to next number
    }
    return 0;
}