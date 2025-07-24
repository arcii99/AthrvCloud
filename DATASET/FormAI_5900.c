//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the maximum value to generate prime numbers: ");
    scanf("%d", &n);
    
    printf("\nThe prime numbers between 1 and %d are: \n", n);
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}