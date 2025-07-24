//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: automated
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

void prime_generator(int lower_bound, int upper_bound) {
    printf("The prime numbers between %d and %d are:\n", lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
}

int main(void) {
    int lower_bound, upper_bound;
    printf("Enter the lower bound: ");
    scanf("%d", &lower_bound);
    printf("Enter the upper bound: ");
    scanf("%d", &upper_bound);
    prime_generator(lower_bound, upper_bound);
    return 0;
}