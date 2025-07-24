//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    printf("Enter an integer n (n > 0): ");
    scanf("%d", &n);
    
    printf("Prime numbers between 1 and %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    
    return 0;
}