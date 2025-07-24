//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>

int isPrime(int num) {
    int i;
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num % 2 == 0 || num == 1) {
        return 0;
    }
    for (i = 3; i*i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i, num = 2, count = 0;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");

    return 0;
}