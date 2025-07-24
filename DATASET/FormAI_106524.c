//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>

int is_prime(int n);

int main() {
    printf("Enter the range of prime numbers you want to generate: ");
    int limit;
    scanf("%d", &limit);

    printf("Prime numbers from 1 to %d are:\n", limit);
    for(int i=2; i<=limit; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}

int is_prime(int n) {
    if(n<2) {
        return 0;
    }

    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            return 0;
        }
    }

    return 1;
}