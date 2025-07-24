//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>

int isPrime(int num);

int main() {
    int maxNum;
    printf("Enter the maximum number to generate primes: ");
    scanf("%d", &maxNum);
    printf("The prime numbers between 2 and %d are: \n", maxNum);

    for (int i = 2; i <= maxNum; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int isPrime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }
    int i = 5;
    int w = 2;
    while (i * i <= num) {
        if (num % i == 0) {
            return 0;
        }
        i += w;
        w = 6 - w;
    }
    return 1;
}