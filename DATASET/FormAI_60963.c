//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX 1000000

// Function to check if a given number is prime or not
int isPrime(int num) {
    if(num == 2 || num == 3)
        return 1;
    if(num == 1 || num % 2 == 0)
        return 0;
    for(int i = 3; i * i <= num; i += 2) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

// Function to calculate Greatest Common Divisor
int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to calculate modulo inverse of a number
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        // m is remainder now, process same as Euclid's algorithm
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    // Make sure x1 is positive
    if (x1 < 0)
       x1 += m0;
    return x1;
}

// Function to generate public and private keys
void generateKeys(int * pub_key, int * priv_key) {
    srand(time(NULL));
    int p = rand() % MAX + 1;
    // Find first prime number greater than p
    while(!isPrime(p))
        p++;
    int q = rand() % MAX + 1;
    // Find first prime number greater than q
    while(!isPrime(q))
        q++;
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = rand() % (phi_n - 2) + 2;
    // Find e such that e and phi_n are coprime
    while(gcd(e, phi_n) != 1)
        e++;
    *pub_key = e;
    *priv_key = modInverse(e, phi_n);
}

// Function to encrypt a message
int encrypt(int message, int pub_key, int n) {
    return (int)pow(message, pub_key) % n;
}

// Function to decrypt a message
int decrypt(int message, int priv_key, int n) {
    return (int)pow(message, priv_key) % n;
}

// Main function
int main() {
    int pub_key, priv_key;
    generateKeys(&pub_key, &priv_key);
    printf("Public Key: %d\n", pub_key);
    printf("Private Key: %d\n", priv_key);
    int message;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    int encrypted = encrypt(message, pub_key, priv_key);
    printf("Encrypted Message: %d\n", encrypted);
    int decrypted = decrypt(encrypted, priv_key, pub_key);
    printf("Decrypted Message: %d\n", decrypted);
    return 0;
}