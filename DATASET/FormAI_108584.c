//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>

int isPrime(int n) {

    if (n <= 1) return 0; // 0 and 1 are not prime numbers

    for(int i=2; i*i<=n; i++) {
        if(n%i == 0)
            return 0; // if n is perfectly divisible by any number other than 1 and n return false
    }

    return 1; // if no number divides n perfectly return true
}

void generatePrimes(int n) {

    printf("The Prime numbers below %d are:\n", n);

    for(int i=2; i<=n; i++) {
        if(isPrime(i))
            printf("%d ", i); // print the prime number
    }
}

int main() {

    int n;

    printf("Enter the upper limit: ");
    scanf("%d", &n);

    generatePrimes(n);

    return 0;
}