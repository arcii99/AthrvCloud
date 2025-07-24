//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME 2000003 // Larger prime number for modulo operation

// Calculates the modular exponentiation (base^e) mod m
int mod_exp(int base, int e, int m) {
    int result = 1;
    base %= m;
    while (e > 0) {
        if (e % 2 == 1)
            result = (result * base) % m;
        e /= 2;
        base = (base * base) % m;
    }
    return result;
}

// Returns 1 if n is prime, 0 otherwise
int is_prime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6;
    }
    return 1;
}

// Generates a random prime number
int get_prime() {
    int prime;
    do {
        prime = rand() % PRIME;
    } while (!is_prime(prime));
    return prime;
}

// Generates a public-private key pair
void generate_keys(int* public_key, int* private_key) {
    // Generate two random prime numbers p and q
    int p = get_prime();
    int q = get_prime();

    // Calculate n=p*q and phi=(p-1)*(q-1)
    int n = p * q;
    int phi = (p-1) * (q-1);

    // Choose an integer e such that 1 < e < phi and e is coprime to phi
    int e = 2; // starting with 2 as the smallest prime number
    while (e < phi) {
        if (phi % e == 0) { // e is not coprime to phi
            e++;
            continue;
        }
        int gcd = 1, k = 1;
        while (gcd != 1) {
            e = 2 + k*phi / (10 - k);
            k++;
            if (e >= phi)
                break;
            // Calculate greatest common divisor of e and phi
            for (int i = 1; i <= e && i <= phi; i++) {
                if (e % i == 0 && phi % i == 0)
                    gcd = i;
            }
        }
        if (e >= phi)
            continue;
        // Found e that is coprime to phi
        break;
    }

    // Calculate the modular multiplicative inverse d of e modulo phi such that (d*e) mod (phi) = 1
    int d = 1;
    while ((d*e) % phi != 1)
        d++;

    *public_key = n; // Public key is n and e
    *(public_key+1) = e;
    *private_key = d; // Private key is d and n
    *(private_key+1) = n;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int public_key[2], private_key[2];
    generate_keys(public_key, private_key);
    printf("Public key: (%d, %d)\n", public_key[0], public_key[1]);
    printf("Private key: (%d, %d)\n", private_key[0], private_key[1]);

    // Message encryption
    char message[20];
    printf("Enter message to encrypt (max 20 characters): ");
    fgets(message, 20, stdin);
    int encrypted_message[20] = {0};
    for (int i = 0; message[i] != '\n' && message[i] != '\0'; i++) {
        int c = (int) message[i];
        encrypted_message[i] = mod_exp(c, public_key[1], public_key[0]);
    }

    // Message decryption
    printf("Encrypted message: ");
    for (int i = 0; encrypted_message[i] != 0; i++)
        printf("%d ", encrypted_message[i]);
    printf("\n");
    printf("Decrypting message...\n");
    char decrypted_message[20];
    for (int i = 0; encrypted_message[i] != 0; i++) {
        int c = mod_exp(encrypted_message[i], private_key[0], private_key[1]);
        decrypted_message[i] = (char) c;
    }
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}