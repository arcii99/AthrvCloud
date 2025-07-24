//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct {
    long long p;
    long long q;
    long long n;
    long long phi_n;
    long long e;
    long long d;
} rsa_key_pair;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int generate_prime_number() {
    int n;
    do {
        n = rand() % 1000; // randomly generating numbers up to 1000
    } while (!is_prime(n));
    return n;
}

int mod_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}

rsa_key_pair rsa_generate_keys(long long p, long long q) {
    rsa_key_pair keys;
    keys.p = p;
    keys.q = q;
    keys.n = p * q;
    keys.phi_n = (p - 1) * (q - 1);
    keys.e = 23; // a common value for e
    while (gcd(keys.phi_n, keys.e) > 1 && keys.e < keys.phi_n) {
        keys.e++;
    }
    keys.d = mod_inverse(keys.e, keys.phi_n);
    printf("Public Key: (%lld , %lld)\n", keys.e, keys.n);
    printf("Private Key: (%lld , %lld)\n", keys.d, keys.n);
    return keys;
}

long long rsa_encrypt(long long message, rsa_key_pair keys) {
    long long encrypted_message = pow(message, keys.e);
    encrypted_message = fmod(encrypted_message, keys.n);
    return encrypted_message;
}

long long rsa_decrypt(long long encrypted_message, rsa_key_pair keys) {
    long long decrypted_message = pow(encrypted_message, keys.d);
    decrypted_message = fmod(decrypted_message, keys.n);
    return decrypted_message;
}

int main() {
    srand(time(NULL)); // generating random number using current time as seed
    long long message, encrypted_message, decrypted_message;
    rsa_key_pair keys;
    int p, q;
    printf("Welcome to RSA Public-Key Algorithm Implementation!\n");
    printf("Generating two random prime numbers...\n");
    p = generate_prime_number();
    q = generate_prime_number();
    printf("Generated two prime numbers: %d , %d\n", p, q);
    keys = rsa_generate_keys(p, q);
    printf("Please enter a message to encrypt: ");
    scanf("%lld", &message);
    encrypted_message = rsa_encrypt(message, keys);
    printf("Encrypted Message: %lld\n", encrypted_message);
    decrypted_message = rsa_decrypt(encrypted_message, keys);
    printf("Decrypted Message: %lld\n", decrypted_message);
    return 0;
}