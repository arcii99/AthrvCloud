//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if(number <= 1) {
        return false;
    }
    for(int i = 2; i*i <= number; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number up to which you want to generate prime numbers: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d:\n", n);
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}