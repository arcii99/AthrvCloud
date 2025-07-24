//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000

long long int generate_prime(long long int min, long long int max) {
    long long int prime;
    do {
        // Generate a random number between min and max
        prime = rand() % (max - min) + min;
    } while (!is_prime(prime)); // Repeat until the number is prime
    return prime;
}

int is_prime(long long int n) {
    long long int i;
    if (n <= 1) return 0; // 1 is not prime
    if (n <= 3) return 1; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0; // Numbers divisible by 2 or 3 are not prime
    for (i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0; // Check if the number is divisible by 6k+1 or 6k-1
    }
    return 1; // The number is prime
}

long long int gcd(long long int a, long long int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

long long int mod_inverse(long long int a, long long int m) {
    long long int m0 = m, t, q;
    long long int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        // m is remainder now
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    // Make x1 positive
    if (x1 < 0) x1 += m0;
    return x1;
}

long long int power(long long int a, long long int b, long long int m) {
    long long int res = 1;
    a = a % m;
    while (b > 0) {
        // If b is odd, multiply a with result
        if (b & 1) res = (res * a) % m;
        // b must be even now
        b = b >> 1; // b = b/2
        a = (a * a) % m;
    }
    return res;
}

void generate_keys(long long int *public_key, long long int *private_key) {
    srand(time(NULL)); // Initialize the random seed
    // Choose two prime numbers p and q
    long long int p = generate_prime(100, 1000);
    long long int q = generate_prime(100, 1000);
    // Calculate n and Euler's totient function phi(n)
    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);
    // Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    long long int e;
    do {
        e = rand() % phi + 1;
    } while (gcd(e, phi) != 1);
    // Calculate the modular inverse of e modulo phi(n)
    long long int d = mod_inverse(e, phi);
    // Set the public and private keys
    *public_key = n;
    *private_key = d;
}

void encrypt(char *message, long long int public_key, char *encrypted_message) {
    int i;
    long long int p, c;
    for (i = 0; message[i] != '\0'; i++) {
        // Convert the character to its ASCII code
        p = message[i];
        // Apply the encryption formula and convert the result back to a character
        c = power(p, public_key, MAX_SIZE);
        encrypted_message[i] = c;
    }
    encrypted_message[i] = '\0'; // Add the string terminator
}

void decrypt(char *encrypted_message, long long int private_key, char *decrypted_message) {
    int i;
    long long int c, p;
    for (i = 0; encrypted_message[i] != '\0'; i++) {
        // Convert the character to its ASCII code
        c = encrypted_message[i];
        // Apply the decryption formula and convert the result back to a character
        p = power(c, private_key, MAX_SIZE);
        decrypted_message[i] = p;
    }
    decrypted_message[i] = '\0'; // Add the string terminator
}

int main() {
    // Generate the public and private keys
    long long int public_key, private_key;
    generate_keys(&public_key, &private_key);

    // Encrypt and decrypt a message
    char message[MAX_SIZE], encrypted_message[MAX_SIZE], decrypted_message[MAX_SIZE];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    encrypt(message, public_key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    decrypt(encrypted_message, private_key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}