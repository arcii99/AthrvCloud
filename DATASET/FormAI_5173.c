//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n == 1 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primeGenerator(int n) {
    int count = 0;
    printf("The prime numbers between 1 and %d are:\n", n);
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    printf("Total count: %d\n", count);
}

int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    primeGenerator(n);
    return 0;
}