//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("Welcome to the Linux Prime Number Generator!\n");
    printf("Enter the maximum number you'd like to generate primes up to: ");

    int max_num;
    scanf("%d", &max_num);

    printf("Generating primes up to %d...\n", max_num);

    for (int i = 2; i <= max_num; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }

    printf("Done!\n");

    return 0;
}