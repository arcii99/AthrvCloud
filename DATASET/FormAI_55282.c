//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
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
    int max_num, num_primes = 0;
    printf("How many primes would you like to generate? ");
    scanf("%d", &max_num);

    int num = 2; // start at first prime number
    while (num_primes < max_num) {
        if (is_prime(num)) {
            printf("%d ", num);
            num_primes++;
        }
        num++;
    }

    return 0;
}