//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i < num; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    int max_range = 100;
    printf("Generating prime numbers up to %d:\n", max_range);

    for (int i = 2; i < max_range; i++) {
        if (is_prime(i)) {
            printf("%d, ", i);
        }
    }

    printf("\n");

    return 0;
}