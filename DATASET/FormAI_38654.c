//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main() {
    int range;
    printf("Enter a range : ");
    scanf("%d", &range);
    printf("Prime numbers between 1 and %d are: ", range);
    for (int i = 2; i <= range; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}

bool isPrime(int n) {
    if (n == 2) {
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