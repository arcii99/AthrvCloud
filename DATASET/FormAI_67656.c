//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// function to generate large prime number
int generate_prime(int min, int max) {
    int i, j, isPrime, num;

    srand(time(NULL));

    while(1) {
        num = (rand() % (max-min)) + min;
        isPrime = 1;

        // check if number is prime
        for(i=2; i<=sqrt(num); i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        // check if number is not equal to 2
        if(num != 2) {
            // check if number is not an even number
            if(num % 2 != 0) {
                // number is prime
                if(isPrime) {
                    return num;
                }
            }
        }
    }
}

// function to find GCD of two numbers
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to generate public and private keys
void generate_keys(int p, int q, int *n, int *e, int *d) {
    int phi, i, flag;

    *n = p * q;
    phi = (p-1) * (q-1);

    do {
        *e = (rand() % (phi-2)) + 2;
    } while(gcd(*e, phi) != 1);

    for(i=1; i<=phi; i++) {
        flag = 0;

        // check if d satisfies condition
        if((((*e) * i) % phi) == 1) {
            *d = i;
            break;
        }
    }
}

// function to encrypt using public key
int encrypt(int plaintext, int e, int n) {
    int i, ciphertext = 1;

    for(i=1; i<=e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }

    return ciphertext;
}

// function to decrypt using private key
int decrypt(int ciphertext, int d, int n) {
    int i, plaintext = 1;

    for(i=1; i<=d; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }

    return plaintext;
}

int main() {
    int p, q, n, e, d, plaintext, ciphertext, decrypted_text;

    // generate two prime numbers
    p = generate_prime(1000, 9999);
    q = generate_prime(1000, 9999);

    // generate public and private keys
    generate_keys(p, q, &n, &e, &d);

    printf("Public Key (n, e): (%d, %d)\n", n, e);
    printf("Private Key (n, d): (%d, %d)\n\n", n, d);

    // read plaintext
    printf("Enter plaintext: ");
    scanf("%d", &plaintext);

    // encrypt plaintext
    ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted text: %d\n", ciphertext);

    // decrypt ciphertext
    decrypted_text = decrypt(ciphertext, d, n);
    printf("Decrypted text: %d\n", decrypted_text);

    return 0;
}