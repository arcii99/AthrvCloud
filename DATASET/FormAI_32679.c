//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PRIME_LIMIT 1000 // limit upper bound for prime numbers

int isPrime(int n){
    // checks if n is a prime number
    int i;
    for(i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int generateRandomPrime(){
    // generates a random prime number within range [1, PRIME_LIMIT]
    int p = rand() % PRIME_LIMIT + 1;
    while(!isPrime(p)){
        p = rand() % PRIME_LIMIT + 1;
    }
    return p;
}

int gcd(int a, int b){
    // computes the greatest common divisor of a and b using Euclid's algorithm
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int generatePublicKey(int p, int q){
    // generates a public key based on two given prime numbers
    int n = p * q;
    int phiN = (p-1) * (q-1);
    int e = rand() % phiN + 1; // choose a random integer e between 1 and phi(n)
    while(gcd(e, phiN) != 1){ // check if gcd(e, phi(n)) = 1
        e = rand() % phiN + 1;
    }
    return e;
}

int generatePrivateKey(int p, int q, int e){
    // generates a private key based on two given prime numbers and a public key
    int n = p * q;
    int phiN = (p-1) * (q-1);
    int d = 1;
    while((d*e) % phiN != 1){ // find d such that ed ≡ 1 mod φ(n)
        d++;
    }
    return d;
}

int encryptMessage(int message, int e, int n){
    // encrypts a given message using a public key (e, n)
    int c = fmod(pow(message, e), n); // c = message^e mod n
    return c;
}

int decryptMessage(int encryptedMessage, int d, int n){
    // decrypts a given message using a private key (d, n)
    int m = fmod(pow(encryptedMessage, d), n); // m = c^d mod n
    return m;
}

int main(){
    // generate two random prime numbers
    srand(time(NULL)); // seed the random number generator with the current time
    int p = generateRandomPrime();
    int q = generateRandomPrime();

    // generate public and private keys based on the prime numbers
    int e = generatePublicKey(p, q);
    int d = generatePrivateKey(p, q, e);

    // print out the public and private keys
    printf("Public key (e, n): (%d, %d)\n", e, p*q);
    printf("Private key (d, n): (%d, %d)\n", d, p*q);

    // encrypt and decrypt a message using the public and private keys
    int message = 42; // example message
    int encryptedMessage = encryptMessage(message, e, p*q);
    int decryptedMessage = decryptMessage(encryptedMessage, d, p*q);
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}