//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);

int main() {
    
    int n, i, count;
    
    printf("Enter the maximum number to generate prime numbers: ");
    scanf("%d", &n);
    
    int primes[n+1];
    
    count = 0;
    
    for(i=2; i<=n; i++) {
        if(is_prime(i)) {
            primes[count++] = i;
        }
    }
    
    printf("\nPrime numbers generated: ");
    for (i=0; i<count; i++) {
        printf("%d ", primes[i]);
    }

    return 0;
}

bool is_prime(int n) {
    
    int i;
    
    if(n<2) {
        return false;
    }
    
    for(i=2; i*i<=n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    
    return true;
}