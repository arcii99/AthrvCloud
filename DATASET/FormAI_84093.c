//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include<stdio.h>

int is_prime(int n) { // helper function to check if a number is prime
    if(n<=1) return 0; // 0 and 1 are not primes
    if(n==2) return 1; // 2 is prime
    if(n%2==0) return 0; // other even numbers are not primes
    for(int i=3;i*i<=n;i+=2) // we only need to check odd numbers from 3 to sqrt(n)
        if(n%i==0) return 0; // if a number divides n, then n is not a prime
    return 1; // if no number divides n, then n is a prime
}

int main() {
    int primes[100000], n = 0;
    primes[n++] = 2; // 2 is the first prime
    for(int i=3;;i+=2) { // we only need to check odd numbers
        if(is_prime(i)) primes[n++] = i; // if a number is prime, add it to the array
        if(n>=100000) break; // we only need 100000 primes
    }
    for(int i=0;i<100000;i++) printf("%d ",primes[i]); // print the primes
    return 0;
}