//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Printing prime numbers between 1 and %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    return 0;
}