//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i = 1, count = 0;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        i++;
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}