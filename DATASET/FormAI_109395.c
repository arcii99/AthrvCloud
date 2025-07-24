//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if(n == 2) {
        return true;
    }
    if(n < 2 || n % 2 == 0) {
        return false;
    }
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the upper limit for prime numbers: ");
    scanf("%d", &n);
    printf("Prime numbers between 1 and %d:\n", n);
    for(int i = 2; i <= n; i++) {
        if(is_prime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}