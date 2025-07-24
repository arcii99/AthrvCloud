//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find gcd of two numbers
int gcd(int a, int b) {
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

// Function to generate a random prime number
int generatePrime() {
    int num, i, isPrime = 1;
    while (isPrime) {
        num = rand() % 100 + 1;
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 1;
                break;
            }
            isPrime = 0;
        }
    }
    return num;
}

int main() {
    int p, q, n, phi, e, d, message, encrypt, decrypt;
    
    // Generate random prime numbers
    p = generatePrime();
    q = generatePrime();
    
    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);
    
    // Choose an integer e such that gcd(e, phi) = 1
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    
    // Calculate d such that d*e = 1 mod phi
    d = 1;
    while (((d * e) % phi) != 1) {
        d++;
    }
    
    printf("Public Key: (%d, %d)\n", n, e);
    printf("Private Key: (%d, %d)\n", n, d);
    
    // Enter message to be encrypted
    printf("Enter a message to be encrypted: ");
    scanf("%d", &message);
    
    // Calculate the encryption and decryption
    encrypt = pow(message, e);
    encrypt = encrypt % n;
    decrypt = pow(encrypt, d);
    decrypt = decrypt % n;
    
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypt);
    printf("Decrypted message: %d\n", decrypt);
    
    return 0;
}