//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {

    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {

    printf("Enter the upper limit: ");
    int limit;
    scanf("%d", &limit);

    printf("The prime numbers between 1 and %d are:\n", limit);

    for (int num = 2; num <= limit; num++) {

        if (is_prime(num)) {
            printf("%d ", num);
        }
    }

    return 0;
}