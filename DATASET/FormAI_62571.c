//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>

int is_prime(int n) {
    int i;

    if (n == 2) return 1;
    if (n % 2 == 0 || n == 1) return 0;

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main() {
    int n, i = 2, count = 0;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }

        i++;
    }

    printf("\n");

    return 0;
}