//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

int isPrime(int num) {
    int i;
    for (i=2; i<num; i++) {
        if(num%i==0)
            return 0; // not prime
    }
    return 1; // prime
}

int main() {
    int n, i, isPrimeFlag;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    int primes[n]; // to store the generated prime numbers
    primes[0] = 2; // first prime number

    for (i=1; i<n; i++) {
        int num = primes[i-1] + 1; // start checking for prime numbers from the next number after the last generated prime
        isPrimeFlag = 0; // assume num is not prime initially
        
        while (!isPrimeFlag) { // keep checking until num is a prime
            if (isPrime(num)) {
                primes[i] = num; // store the generated prime number in the array
                isPrimeFlag = 1; // set the flag to exit the loop
            }
            else {
                num++; // try the next number
            }
        }
    }

    // print the generated prime numbers
    printf("Generated prime numbers: ");
    for (i=0; i<n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}