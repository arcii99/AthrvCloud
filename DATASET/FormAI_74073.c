//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include <stdio.h>

int main() {

    int n, i, flag = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if 1 is a prime number
    if (n == 1) {
        printf("1 is neither a prime nor a composite number.");
    }

    // Check whether n is a prime number or not
    for (i = 2; i <= n / 2; ++i) {

        // If n is divisible by i, flag set to 1
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 2) {
        printf("%d is a prime number.", n);
    }
    else {
        // If flag is 0, the number is prime
        if (flag == 0)
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }

    return 0;
}