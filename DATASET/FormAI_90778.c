//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRIME 1000
#define BLOCK_SIZE 16

typedef struct {
    int n;
    int e;
} public_key;

typedef struct {
    int n;
    int d;
} private_key;

int is_prime(int n) {
    int i;
    if (n <= 1) return 0;
    for (i=2; i*i<=n; i++) {
        if (n%i == 0) return 0;
    }
    return 1;
}

void generate_key_pair(public_key *pub, private_key *pvt) {
    int p, q, n, phi, e, d;
    int primes[MAX_PRIME], num_primes = 0;
    int i, j;

    // populate primes array with all primes up to MAX_PRIME
    for (i=2; i<MAX_PRIME; i++) {
        if (is_prime(i)) {
            primes[num_primes] = i;
            num_primes++;
        }
    }

    // choose two different primes p and q
    p = primes[rand()%num_primes];
    do {
        q = primes[rand()%num_primes];
    } while (q == p);

    // calculate n and phi
    n = p*q;
    phi = (p-1)*(q-1);

    // choose an integer 1 < e < phi such that gcd(phi, e) = 1
    for (i=2; i<phi; i++) {
        if (is_prime(i) && phi%i != 0) {
            e = i;
            break;
        }
    }

    // calculate d such that d*e = 1 (mod phi)
    for (i=1; i<phi; i++) {
        j = (i*e) % phi;
        if (j == 1) {
            d = i;
            break;
        }
    }

    pub->n = n;
    pub->e = e;
    pvt->n = n;
    pvt->d = d;
}

void encrypt(public_key *pub, char *msg, int msg_len, int *cipher) {
    int i;
    for (i=0; i<msg_len; i++) {
        cipher[i] = (int)pow((double)msg[i], (double)pub->e) % pub->n;
    }
}

void decrypt(private_key *pvt, int *cipher, int msg_len, char *msg) {
    int i;
    for (i=0; i<msg_len; i++) {
        msg[i] = (char)pow((double)cipher[i], (double)pvt->d) % pvt->n;
    }
}

int main() {
    public_key pub;
    private_key pvt;
    char msg[] = "Hello, World!";
    int cipher[BLOCK_SIZE];
    char decrypted[BLOCK_SIZE];
    int i;

    // generate key pair
    generate_key_pair(&pub, &pvt);

    // encrypt message
    encrypt(&pub, msg, BLOCK_SIZE, cipher);

    // decrypt cipher
    decrypt(&pvt, cipher, BLOCK_SIZE, decrypted);

    // print original, encrypted, and decrypted messages
    printf("Original message: %s\n", msg);
    printf("Encrypted message:");
    for (i=0; i<BLOCK_SIZE; i++) {
        printf(" %d", cipher[i]);
    }
    printf("\nDecrypted message: %s\n", decrypted);

    return 0;
}