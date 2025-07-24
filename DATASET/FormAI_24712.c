//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("C Prime Number Generator\n");

    int count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &count);

    printf("The first %d prime numbers are:\n", count);

    int num = 2;
    int prime_count = 0;
    while (prime_count < count) {
        if (is_prime(num)) {
            printf("%d ", num);
            prime_count++;
        }
        num++;
    }

    printf("\n");

    return 0;
}