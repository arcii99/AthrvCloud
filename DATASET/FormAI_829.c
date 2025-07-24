//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num, count = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("The prime numbers up to %d are: \n", num);

    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal number of prime numbers found: %d", count);
    return 0;
}