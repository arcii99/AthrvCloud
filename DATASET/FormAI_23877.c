//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for(i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generatePrime() {
    int num = rand() % 1000 + 1000;
    while(!isPrime(num)) {
        num++;
    }
    return num;
}

// Function to find the greatest common divisor
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

// Function to find the modular inverse of a number
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1) return 0;
 
    while (a > 1) {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as Euclid's
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0) x1 += m0;
 
    return x1;
}

int main() {
    int p, q, n, totient, e, d, message, encrypted_message, decrypted_message;

    // Generate two random prime numbers
    p = generatePrime();
    q = generatePrime();

    // Compute n and totient
    n = p * q;
    totient = (p - 1) * (q - 1);

    // Choose a random number e coprime to totient
    do {
        e = rand() % totient;
    } while(gcd(e, totient) != 1);

    // Compute the private key d
    d = modInverse(e, totient);

    printf("Public key pair: (%d, %d)\n", n, e);
    printf("Private key: %d\n", d);

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);

    // Encrypt the message
    encrypted_message = fmod(pow(message, e), n);
    printf("Encrypted message: %d\n", encrypted_message);

    // Decrypt the message
    decrypted_message = fmod(pow(encrypted_message, d), n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}