//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
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
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);
    int i = 2;
    while (n > 0) {
        if (is_prime(i)) {
            printf("%d ", i);
            n--;
        }
        i++;
    }
    return 0;
}