//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_generator(int start, int end) {
    if (start >= end) {
        printf("Invalid Range!");
        return;
    }
    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int i = start; i < end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Enter the starting number of the range: ");
    scanf("%d", &start);

    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    prime_generator(start, end);

    return 0;
}