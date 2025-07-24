//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void prime_gen(int n) {
    int i = 2;
    int count = 0;
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
}

int main() {
    int n;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter how many prime numbers you would like to generate: ");
    scanf("%d", &n);
    prime_gen(n);
    printf("\nThank you for using the Prime Number Generator!\n");
    return 0;
}