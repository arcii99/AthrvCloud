//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>

int isPrime(int num) {
    int i;

    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n, i, count = 0;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are: ", n);

    for (i = 2; count < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }

    return 0;
}