//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num, i, limit;
    bool isPrime;
    
    printf("Enter the limit of prime numbers to generate: ");
    scanf("%d", &limit);
    printf("The first %d prime numbers are: ", limit);
 
    // 2 is the first prime number
    printf("2, ");
 
    // Start from 3, check all odd numbers for prime
    for (num = 3; num <= limit; num += 2) {
        isPrime = true;
        
        // Check if num is divisible by any odd number less than it
        for (i = 3; i < num; i += 2) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        // If num is prime, print it
        if (isPrime) {
            printf("%d, ", num);
        }
    }
    
    return 0;
}