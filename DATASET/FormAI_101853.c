//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate GCD
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to generate Public and Private Keys
void generateKeys(int prime1, int prime2) {
    // Calculate Modulus
    int modulus = prime1 * prime2;

    // Calculate Totient
    int totient = (prime1 - 1) * (prime2 - 1);

    // Find a number co-prime to totient
    int publicKey = 2;

    while(publicKey < totient) {
        if(gcd(publicKey, totient) == 1) {
            break;
        } 
        else {
            publicKey++;
        }
    }

    // Calculate Private Key
    int privateKey = 0;

    while(privateKey < totient) {
        if(((publicKey * privateKey) % totient) == 1) {
            break;
        } 
        else {
            privateKey++;
        }
    }

    printf("Public Key (e,n): (%d,%d)\n", publicKey, modulus);
    printf("Private Key (d,n): (%d,%d)\n", privateKey, modulus);
}

int main() {
    int prime1 = 53;
    int prime2 = 59;

    generateKeys(prime1, prime2);

    return 0;
}