//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Public key struct
typedef struct {
    int x;
    int y;
} PublicKey;

// Private key struct
typedef struct {
    int p;
    int q;
    int e;
} PrivateKey;

// Function to generate prime numbers
int generatePrime() {
    int isPrime = 0;
    int num = 0;
    
    // Generate random number until prime is found
    while(!isPrime) {
        num = rand() % 200 + 1;
        isPrime = 1;
        
        // Check if number is prime
        for(int i = 2; i < num; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    
    return num;
}

// Function to calculate greatest common divisor
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to generate public and private keys
void generateKeys(PublicKey *publicKey, PrivateKey *privateKey) {
    int p, q, n, phi, e, d;
    
    // Generate two prime numbers
    p = generatePrime();
    q = generatePrime();
    
    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);
    
    // Choose e (public key)
    e = 2;
    while(gcd(phi, e) != 1) {
        e++;
    }
    
    // Calculate d (private key)
    d = 0;
    for(int i = 1; i < phi; i++) {
        if((e * i) % phi == 1) {
            d = i;
            break;
        }
    }
    
    // Set public and private keys
    publicKey->x = n;
    publicKey->y = e;
    
    privateKey->p = p;
    privateKey->q = q;
    privateKey->e = d;
}

// Function to encrypt message
int encrypt(int message, PublicKey publicKey) {
    return (int)pow(message, publicKey.y) % publicKey.x;
}

// Function to decrypt message
int decrypt(int message, PrivateKey privateKey) {
    return (int)pow(message, privateKey.e) % (privateKey.p * privateKey.q);
}

int main() {
    srand(time(0));
    PublicKey publicKey;
    PrivateKey privateKey;
    int message, cipher, decryptedMessage;
    
    // Generate public and private keys
    generateKeys(&publicKey, &privateKey);
    
    // Get message from user
    printf("Enter message: ");
    scanf("%d", &message);
    
    // Encrypt message
    cipher = encrypt(message, publicKey);
    
    // Decrypt message
    decryptedMessage = decrypt(cipher, privateKey);
    
    // Print results
    printf("Public Key: (%d, %d)\n", publicKey.x, publicKey.y);
    printf("Private Key: (%d, %d, %d)\n", privateKey.p, privateKey.q, privateKey.e);
    printf("Message: %d\n", message);
    printf("Cipher: %d\n", cipher);
    printf("Decrypted Message: %d\n", decryptedMessage);
    
    return 0;
}