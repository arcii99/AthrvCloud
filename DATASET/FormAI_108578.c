//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>

void generatePrimes(int n) {
    int num[n+1]; // Array to keep track of prime numbers
    for(int i=0; i<=n; i++) {
        num[i] = 1; //Initialize all elements to 1, assuming every number is prime
    }

    for(int i=2; i*i<=n; i++) {
        // Check if the number is prime
        if(num[i] == 1) {
            // Mark all multiples of i as not prime
            for(int j=i*i; j<=n; j+=i) {
                num[j] = 0;
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers between 2 and %d are:\n", n);
    for(int i=2; i<=n; i++) {
        if(num[i] == 1) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter a positive integer n: ");
    scanf("%d", &n);
    generatePrimes(n);
    return 0;
}