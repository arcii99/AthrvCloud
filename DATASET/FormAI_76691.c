//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>

int isPrime(int num);

int main() {
    int limit, primeCount = 0;
    printf("Enter the limit up to which you want to generate prime numbers: ");
    scanf("%d", &limit);
    printf("The prime numbers from 2 to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            primeCount++;
        }
    }
    printf("\nTotal number of prime numbers found: %d\n", primeCount);
    return 0;
}

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}