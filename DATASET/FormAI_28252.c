//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>

int is_prime(int n);

int main(void) {
    int num, prime_count = 0, i = 2;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);
    printf("The first %d prime numbers are:\n", num);
    while (prime_count < num) {
        if (is_prime(i)) {
            printf("%d\n", i);
            prime_count++;
        }
        i++;
    }
    return 0;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}