//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);

    printf("The prime numbers from 2 to %d are:\n", n);

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}