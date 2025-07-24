//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n == 2 || n == 3) {
        return 1;
    }
    else if (n == 1 || n % 2 == 0) {
        return 0;
    }
    else {
        int i;
        for (i = 3; i <= sqrt(n); i += 2) {
            if(n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

// Function to generate a random prime number
int generateRandomPrime() {
    int n = rand() % 100 + 1; // Generate a random number between 1 and 100
    while (!isPrime(n)) { // Loop until a prime number is generated
        n = rand() % 100 + 1;
    }
    return n;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

// Function to calculate the public and private keys
void generateKeys(int p, int q, int *publicKey, int *privateKey) {
    int n = p * q;
    int phi = (p - 1) * (q - 1); // Compute Euler's totient function
    
    // Choose a random integer e such that 1 < e < phi and gcd(e, phi) = 1
    int e = rand() % phi + 1;
    while (gcd(e, phi) != 1) {
        e = rand() % phi + 1;
    }
    *publicKey = e;
    
    // Compute d such that d*e mod phi = 1
    int k = 1;
    while (((k * phi) + 1) % e != 0) {
        k++;
    }
    *privateKey = ((k * phi) + 1) / e;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate two random prime numbers
    int p = generateRandomPrime();
    int q = generateRandomPrime();
    
    // Generate public and private keys
    int publicKey, privateKey;
    generateKeys(p, q, &publicKey, &privateKey);
    
    printf("Public key: %d\n", publicKey);
    printf("Private key: %d\n", privateKey);
}