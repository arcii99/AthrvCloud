//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>

int main(void) {
    int counter, n, i, flag;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: ", n);

    // loop through all the numbers until we reach n prime numbers
    for (counter = 2; counter <= n; ) {
        flag = 0;

        // check if the current number is a prime number
        for (i = 2; i <= counter / 2; ++i) {
            if (counter % i == 0) {
                flag = 1;
                break;
            }
        }

        // if the current number is prime, print it and increment the counter
        if (flag == 0) {
            printf("%d ", counter);
            ++counter;
        }

        // if the current number is not prime, move on to the next number
        else {
            ++counter;
        }
    }

    return 0;
}