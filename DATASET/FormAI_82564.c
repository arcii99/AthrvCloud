//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>

int isPrime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num == 1 || num % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);

    int count = 0;
    int num = 1;
    while (count < n) {
        num++;
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
    }

    printf("\n");

    return 0;
}