//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    int i;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i, num = 1, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("First %d prime numbers:\n", n);
    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            ++count;
        }
        ++num;
    }
    return 0;
}