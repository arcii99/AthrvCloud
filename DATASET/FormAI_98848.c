//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>

void main() {
    int n, i, flag = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // handling edge cases
    if (n <= 1) {
        printf("%d is not a prime number!\n", n);
        return;
    }

    // loop through all numbers up to n and check for factors
    for (i = 2; i <= n/2; ++i) {

        // if n is divisible by i, it is not a prime number
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%d is a prime number!\n", n);
    else
        printf("%d is not a prime number!\n", n);
}