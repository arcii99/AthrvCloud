//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// recursive implementation of the euclidean algorithm
long gcd(long a, long b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// uses the extended euclidean algorithm to calculate the modular multiplicative inverse
long modInverse(long a, long m) {
    long m0 = m;
    long x0 = 0, x1 = 1;
    long gcd, temp;
    if(m == 1) {
        return 0;
    }
    while(a > 1) {
        gcd = a / m;
        temp = m;
        m = a % m;
        a = temp;
        temp = x0;
        x0 = x1 - gcd * x0;
        x1 = temp;
    }
    if(x1 < 0) {
        x1 += m0;
    }
    return x1;
}

// generates a random number between 0 and 25 (inclusive) to be used as a shift value
int generateRandom() {
    srand(time(NULL));
    return rand() % 26;
}

// encrypts a message using the Caesar cipher
void encryptMessage(char message[], int shift) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((message[i] + shift - 'a') % 26) + 'a');
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((message[i] + shift - 'A') % 26) + 'A');
        }
    }
    printf("Encrypted message: %s\n", message);
}

// decrypts a message using the Caesar cipher
void decryptMessage(char message[], int shift) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((message[i] - shift - 'a') + 26) % 26 + 'a');
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((message[i] - shift - 'A') + 26) % 26 + 'A');
        }
    }
    printf("Decrypted message: %s\n", message);
}

int main() {
    long p, q, n, phi, e, d, plaintext, ciphertext;
    char message[100];
    int shift;
    
    printf("Enter a message: ");
    fgets(message, 100, stdin); // takes user input for message to be encrypted/decrypted
    printf("Original message: %s", message);
    
    shift = generateRandom(); // generates random shift value between 0 and 25 (inclusive)
    printf("Shift: %d\n", shift);
    encryptMessage(message, shift); // encrypts message using Caesar cipher
    decryptMessage(message, shift); // decrypts message using Caesar cipher
    
    printf("Enter a prime number p: ");
    scanf("%ld", &p);
    printf("Enter a prime number q: ");
    scanf("%ld", &q);
    
    n = p * q; // calculates n
    phi = (p - 1) * (q - 1); // calculates phi(n)
    
    srand(time(NULL)); // seed for random number generator
    e = rand() % phi; // generates random e
    while(gcd(e, phi) != 1) { // checks if e and phi(n) are coprime
        e = rand() % phi;
    }
    
    d = modInverse(e, phi); // calculates d using the extended euclidean algorithm
    
    printf("Public key (n, e): (%ld, %ld)\n", n, e);
    printf("Private key (n, d): (%ld, %ld)\n", n, d);
    
    printf("Enter a number to encrypt: ");
    scanf("%ld", &plaintext); // takes user input for number to be encrypted
    ciphertext = ((long)pow(plaintext, e)) % n; // calculates ciphertext using public key
    printf("Ciphertext: %ld\n", ciphertext);
    
    plaintext = ((long)pow(ciphertext, d)) % n; // calculates plaintext using private key
    printf("Plaintext: %ld\n", plaintext);

    return 0;
}