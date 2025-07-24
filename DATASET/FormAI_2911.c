//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i=2; i<=num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    printf("First %d prime numbers are:\n", n);

    for (int num=2; count<n; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
    }
    printf("\n");

    return 0;
}