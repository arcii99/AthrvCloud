//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>

int isPrime(int num);

int main() {
    int n, count = 0;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 2; count < n; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
            count++;
        }
    }
    return 0;
}

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}