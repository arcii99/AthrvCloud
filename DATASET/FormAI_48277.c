//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>

int isPrimeNumber(int number);

int main() {

    int n, i, primeFound = 0;

    printf("Enter the number up to which prime numbers are to be found: ");
    scanf("%d", &n);

    for (i = 2; i <= n; i++) {
        if (isPrimeNumber(i) == 1) {
            primeFound = 1;
            printf("%d ", i);
        }
    }

    if (primeFound == 0) {
        printf("No prime numbers found up to %d", n);
    }

    return 0;
}

int isPrimeNumber(int number) {

    int i;
    for (i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}