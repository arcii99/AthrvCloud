//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    
    int num, i, j, isPrime;
    printf("Enter a number to generate all prime numbers up to and including that number: ");
    scanf("%d", &num);
    
    // check all numbers up to num
    for (i = 2; i <= num; i++) {
        isPrime = 1; // assume i is prime
        
        // check if i is not prime
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0; // i is not prime
                break;
            }
        }
        
        // if i was prime, print it
        if (isPrime) {
            printf("%d ", i);
        }
    }
    
    printf("\nThanks for using the Prime Number Generator!\n");
    
    return 0;
}