//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to determine if a number is prime
int isPrime(int num) {
    if(num == 2) return 1;
    if(num % 2 == 0 || num == 1) return 0;
    for(int i=3; i<=sqrt(num); i+=2)
        if(num % i == 0) return 0;
    return 1;
}

// Function to generate a random prime number of given length
int generatePrime(int length) {
    int min = pow(10, length - 1);
    int max = pow(10, length) - 1;
    int num;
    do {
        num = (rand() % (max - min + 1)) + min;
    } while(!isPrime(num));
    return num;
}

// Function to calculate modular exponentiation
int modExp(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Function to calculate greatest common divisor
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to generate a public and private key pair
void generateKeys(int length, int *e, int *d, int *N) {
    srand(time(NULL)); // initialize random seed
    int p = generatePrime(length); // generate random prime p
    int q = generatePrime(length); // generate random prime q
    int phi = (p - 1) * (q - 1); // calculate phi(n)
    int E;
    do {
        E = rand() % phi; // generate random E such that E and phi(n) are coprime
    } while(gcd(E, phi) != 1);
    int D = 0;
    while((D * E) % phi != 1) {
        D++;
    }
    *e = E;
    *d = D;
    *N = p * q;
}

int main() {
    int length = 4; // length of prime number
    int e, d, N;
    generateKeys(length, &e, &d, &N);
    printf("Public Key: {%d, %d}\n", e, N);
    printf("Private Key: {%d, %d}\n", d, N);
    return 0;
}