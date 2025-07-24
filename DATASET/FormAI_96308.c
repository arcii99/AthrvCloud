//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num%2 == 0 || num%3 == 0) return false;
    for (int i=5; i*i<=num; i+=6) {
        if (num%i == 0 || num%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    
    printf("Prime numbers: ");
    for (int i=2; count<n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}