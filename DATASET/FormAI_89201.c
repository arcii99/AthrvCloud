//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the upper limit of prime numbers: ");
    scanf("%d", &n);
    
    printf("Prime numbers between 1 to %d are:\n", n);
    
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    return 0;
}