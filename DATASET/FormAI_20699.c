//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>

int isPrime(int n) {
    // Returns 1 if the number is prime, 0 otherwise
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int start, end;
    printf("Enter the start and end range of the numbers to check for prime: ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}