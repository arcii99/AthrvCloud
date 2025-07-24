//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// function to determine if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to generate random prime numbers
int generatePrime() {
    int n;
    do {
        n = rand() % 100;
    } while (!isPrime(n));
    return n;
}

// function to calculate the public key
int calculatePublicKey(int p, int q) {
    int n = p * q;
    int e = rand() % (n - 2) + 2; // choose a random number greater than 1 and less than n
    while (gcd(e, (p - 1) * (q - 1)) != 1) {
        e = rand() % (n - 2) + 2;
    }
    return e;
}

// function to calculate the private key
int calculatePrivateKey(int p, int q, int e) {
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int k = 1;
    int d = (k * phi_n + 1) / e;
    while (d * e % phi_n != 1) {
        k++;
        d = (k * phi_n + 1) / e;
    }
    return d;
}

int main() {
    srand(time(NULL));
    
    int p = generatePrime();
    int q = generatePrime();
    while (p == q) {
        q = generatePrime();
    }
    
    int e = calculatePublicKey(p, q);
    int d = calculatePrivateKey(p, q, e);
    
    int message;
    printf("Enter a message to be encrypted: ");
    scanf("%d", &message);
    
    int n = p * q;
    int encrypted = (int) pow(message, e) % n;
    printf("The encrypted message is: %d\n", encrypted);
    
    int decrypted = (int) pow(encrypted, d) % n;
    printf("The decrypted message is: %d\n", decrypted);

    return 0;
}