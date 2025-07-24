//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
    int n;
    printf("Enter an integer greater than 1: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}