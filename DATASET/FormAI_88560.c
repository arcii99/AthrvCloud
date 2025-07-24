//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit, count = 0;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal prime numbers found: %d\n", count);
    return 0;
}