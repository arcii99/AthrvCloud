//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>

int main() {
    int num, count, isPrime;
    printf("Enter the maximum limit to generate prime numbers: ");
    scanf("%d", &num);
    printf("The prime numbers between 1 and %d are:\n", num);
    // loop through all numbers from 2 to num
    for (int i = 2; i <= num; i++) {
        // assume i is prime until proven otherwise
        isPrime = 1;
        // check if i is divisible by any number from 2 to i-1
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        // if i is prime, print it
        if (isPrime) {
            printf("%d ", i);
            count++;
            // add line break after every 10 primes printed
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n");
    return 0;
}