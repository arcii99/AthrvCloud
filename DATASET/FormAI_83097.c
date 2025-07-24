//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main() {
    int n;
    printf("Enter the number upto which you want to generate prime numbers: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are:\n", n);

    for(int i = 2; i <= n; i++) {
        if(isPrime(i))
            printf("%d ", i);
    }

    return 0;
}

bool isPrime(int n) {
    if(n <= 1) { // 1 is not a prime number
        return false;
    }

    // We only have to check till the square root of n
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}