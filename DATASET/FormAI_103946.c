//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// function to generate a random prime number between min and max
int generatePrime(int min, int max) {
    int num;
    int isPrime;
    
    // seed the random number generator
    srand(time(NULL));
    
    do {
        // generate a random number between min and max
        num = rand() % (max - min + 1) + min;
        
        isPrime = 1;
        
        // check if the number is prime
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    } while (isPrime == 0); // loop until a prime number is generated
    
    return num;
}

// function to find the greatest common divisor of a and b
int gcd(int a, int b) {
    int temp;
    
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

// function to find the multiplicative inverse of e mod n
int multiplicativeInverse(int e, int n) {
    int r1 = n;
    int r2 = e;
    int r, t1, t2, t;
    
    t1 = 0;
    t2 = 1;
    
    while (r2 > 0) {
        int q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    
    if (t1 < 0) {
        t1 += n;
    }
    
    return t1;
}

int main() {
    int p, q, n, phi, e, d, plaintext, ciphertext, decryptedtext;
    
    // generate two random prime numbers
    p = generatePrime(100, 1000);
    q = generatePrime(100, 1000);
    
    // calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);
    
    // generate a random number e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);
    
    // calculate the multiplicative inverse of e mod phi
    d = multiplicativeInverse(e, phi);
    
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    
    // take input from user
    printf("Enter a number to encrypt: ");
    scanf("%d", &plaintext);
    
    // encrypt the plaintext
    ciphertext = fmod(pow(plaintext, e), n);
    
    printf("Encrypted text: %d\n", ciphertext);
    
    // decrypt the ciphertext
    decryptedtext = fmod(pow(ciphertext, d), n);
    
    printf("Decrypted text: %d\n", decryptedtext);
    
    return 0;
}