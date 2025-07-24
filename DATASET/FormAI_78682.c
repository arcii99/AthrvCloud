//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>

void printPrimes(int n) {
    int primes[n+1];
    for(int i=0; i<=n; i++)
        primes[i] = 1;
    primes[0] = 0;
    primes[1] = 0;

    for(int i=2; i<=n/2; i++) {
        if(primes[i]) {
            for(int j=i*2; j<=n; j+=i)
                primes[j] = 0;
        }
    }

    printf("The prime numbers between 1 and %d are: ", n);
    for(int i=2; i<=n; i++) {
        if(primes[i])
            printf("%d ", i);
    }
}

int main() {
    int num;
    printf("Enter an integer greater than or equal to 2: ");
    scanf("%d", &num);
    printPrimes(num);
    return 0;
}