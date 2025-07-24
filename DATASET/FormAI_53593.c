//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>

int main() {
    int n, i, j, flag;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // exception handling for n<2
    if (n < 2) {
        printf("Invalid input");
        return 0;
    }

    printf("Prime numbers between 1 and %d are: \n", n);

    // loop through each number between 2 and n
    for (i = 2; i <= n; i++) {
        flag = 1; // assume number is prime

        // loop through each number between 2 and i/2
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0; // number is not prime
                break;
            }
        }

        // if number is prime, print it
        if (flag == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}