//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

int main() {
    int limit, i, j;
    bool isPrime;

    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers between 1 and %d are: ", limit);

    //loop through all numbers between 1 to limit
    for (i = 2; i <= limit; i++) {
        //set isPrime to true initially
        isPrime = true;

        //check if number i is prime or not
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        //print the prime number
        if (isPrime) {
            printf("%d ", i);
        }
    }

    return 0;
}