//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_primes(int n) {
    bool *prime = malloc(sizeof(bool) * (n+1));
    
    // Set all values of prime to true
    for(int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    // Perform Sieve of Eratosthenes algorithm
    for(int p = 2; p*p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p*p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    // Print the prime numbers
    printf("Prime numbers between 2 and %d are: ", n);
    for(int i = 2; i <= n; i++) {
        if(prime[i] == true) {
            printf("%d ", i);
        }
    }
    
    free(prime);
}

int main() {
    int n;
    printf("Enter the maximum number: ");
    scanf("%d", &n);
    
    print_primes(n);
    
    return 0;
}