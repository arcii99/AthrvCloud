//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>

int isPrime(int n);

int main() {
    int num, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers:\n");
    for (i = 2; i <= num; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

int isPrime(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}