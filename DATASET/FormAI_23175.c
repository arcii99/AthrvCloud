//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_generator(int start, int end) {
    printf("Prime numbers between %d and %d are: \n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int start, end;
    printf("Enter the starting point: ");
    scanf("%d", &start);
    printf("Enter the ending point: ");
    scanf("%d", &end);
    if (start > end) {
        printf("Ending point should be greater than starting point. Try again!\n");
        return 1;
    }
    prime_generator(start, end);
    return 0;
}