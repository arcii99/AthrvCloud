//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // required for srand(), rand() functions
#include <math.h>  // required for pow() and sqrt() functions

int isPrime(int n);
int generateRandomPrime(int a, int b);  // generate random prime between a and b
int gcd(int a, int b);
int modulo(int a, int b, int n);  // calculate (a^b) % n
int extendedEuclidean(int a, int b, int *x, int *y);  // calculate x and y for ax + by = gcd(a,b)
int calculatePrivateKey(int p, int q, int publicKey);

int main()
{
    int p, q;  // randomly generated prime numbers
    int n;  // n = p*q
    int publicKey;  // randomly generated public key
    int privateKey;  // calculated private key
    int x, y;  // used in extended Euclidean algorithm to calculate private key
    char message[] = "Hello, World!";  // message to encrypt and decrypt
    int messageLength = sizeof(message) / sizeof(char);  // length of message
    
    srand(time(0));  // seed for random number generator
    
    // generate two random prime numbers between 100 and 1000
    p = generateRandomPrime(100, 1000);
    q = generateRandomPrime(100, 1000);
    
    n = p*q;  // calculate n
    
    // generate a random public key between 1 and (p-1)*(q-1)
    publicKey = rand() % ((p-1)*(q-1)) + 1;
    
    // calculate the private key using extended Euclidean algorithm
    privateKey = calculatePrivateKey(p, q, publicKey);
    
    // print the public and private keys
    printf("Public Key: %d\nPrivate Key: %d\n", publicKey, privateKey);
    
    // encrypt and decrypt the message using the public and private keys
    int i, encryptedMessage[messageLength], decryptedMessage[messageLength];
    for (i = 0; i < messageLength; i++) {
        // encrypt each character of message using public key
        encryptedMessage[i] = modulo(message[i], publicKey, n);
        // decrypt each character of the encrypted message using private key
        decryptedMessage[i] = modulo(encryptedMessage[i], privateKey, n);
    }
    
    // print the original message, encrypted message, and decrypted message
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for (i = 0; i < messageLength; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");
    printf("Decrypted Message: ");
    for (i = 0; i < messageLength; i++) {
        printf("%c", decryptedMessage[i]);
    }
    printf("\n");
    
    return 0;
}

// function to check if a number is prime
int isPrime(int n)
{
    if (n <= 1) {
        return 0;
    }
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to generate random prime between a and b
int generateRandomPrime(int a, int b)
{
    int n;
    while (1) {
        n = rand() % (b-a+1) + a;  // generate random number between a and b
        if (isPrime(n)) {
            return n;
        }
    }
}

// function to calculate greatest common divisor of two numbers
int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to calculate (a^b) % n
int modulo(int a, int b, int n)
{
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % n;
        }
        a = (a*a) % n;
        b = b / 2;
    }
    return result;
}

// function to calculate x and y for ax + by = gcd(a,b)
int extendedEuclidean(int a, int b, int *x, int *y)
{
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// function to calculate private key using extended Euclidean algorithm
int calculatePrivateKey(int p, int q, int publicKey)
{
    int x, y;
    int phi = (p-1) * (q-1);
    extendedEuclidean(publicKey, phi, &x, &y);
    int privateKey = x;
    if (privateKey < 0) {
        privateKey += phi;
    }
    return privateKey;
}