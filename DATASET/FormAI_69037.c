//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    printf("Prime Numbers between 1 and %d are: ", N);
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}

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