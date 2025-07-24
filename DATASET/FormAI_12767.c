//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0 || num == 1) {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_generator(int limit) {
    printf("The prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter the limit for prime number generation: ");
    scanf("%d", &num);
    prime_generator(num);
    return 0;
}