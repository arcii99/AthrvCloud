//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PRIME_SIZE 10
#define BUFFER_SIZE 100

typedef struct {
    long m_public_key;
    long m_private_key;
} key;

void generate_keys(key *key_pair);
int is_prime(long n);
long generate_prime();
long encrypt(long message, long key, long n);
long decrypt(long cipher, long key, long n);
long find_gcd(long a, long b);

int main() {
    long p, q, n, message, cipher, decrypted;
    key key_pair;

    // Generate public and private keys
    generate_keys(&key_pair);

    printf("Enter message to be encrypted: ");
    scanf("%ld", &message);

    // Encrypt message
    n = p * q;
    cipher = encrypt(message, key_pair.m_public_key, n);
    printf("Cipher: %ld\n", cipher);

    // Decrypt cipher
    decrypted = decrypt(cipher, key_pair.m_private_key, n);
    printf("Decrypted message: %ld\n", decrypted);

    return 0;
}

void generate_keys(key *key_pair) {
    // Generate two prime numbers
    long p = generate_prime();
    long q = generate_prime();

    // Compute n
    long n = p * q;

    // Compute phi_n
    long phi_n = (p - 1) * (q - 1);

    // Find public key such that gcd(public_key, phi_n) = 1
    long public_key = rand() % phi_n;
    while (find_gcd(public_key, phi_n) != 1) {
        public_key = rand() % phi_n;
    }

    // Find the private key
    long private_key = 1;
    while ((private_key * public_key) % phi_n != 1) {
        private_key++;
    }

    key_pair->m_public_key = public_key;
    key_pair->m_private_key = private_key;

    printf("Public key: %ld\n", public_key);
    printf("Private key: %ld\n\n", private_key);

    p = q = n = phi_n = public_key = private_key = 0;
}

int is_prime(long n) {
    if (n == 1 || n == 2) return 1;
    if (n == 0 || n % 2 == 0) return 0;

    for (long i = 3; i < sqrt(n) + 1; i += 2) {
        if (n % i == 0) return 0;
    }

    return 1;
}

long generate_prime() {
    long prime;

    do {
        prime = rand() % ((long) pow(10, PRIME_SIZE) - 1) + (long) pow(10, PRIME_SIZE - 1);
    } while (!is_prime(prime));

    return prime;
}

long encrypt(long message, long key, long n) {
    long cipher = (long) pow(message, key);
    return cipher % n;
}

long decrypt(long cipher, long key, long n) {
    long decrypted = (long) pow(cipher, key);
    return decrypted % n;
}

long find_gcd(long a, long b) {
    if (b == 0) return a;
    else return find_gcd(b, a % b);
}