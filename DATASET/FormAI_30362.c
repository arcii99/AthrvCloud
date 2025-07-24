//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include<stdio.h>

// Function to check if a number is prime or not
int is_prime(int num) {
    int i;
    if (num == 1 || num == 0) {
        return 0;
    }
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);
    for (i = 2; i < 100000; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            n--;
        }
        if (n == 0) {
            break;
        }
    }
    return 0;
}