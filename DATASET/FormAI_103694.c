//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int is_prime(int num){
    int i;

    if (num < 2){
        return 0;
    }

    if (num == 2){
        return 1;
    }

    if (num % 2 == 0){
        return 0;
    }

    for (i = 3; i <= sqrt(num); i += 2){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b){
    int temp;

    while (b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int generate_rsa_keys(int *e, int *d, int *n){
    srand(time(NULL));

    int p, q, phi, limit;
    limit = 100;

    // Generate 2 random prime numbers
    do {
        p = rand() % limit + 1;
    } while (!is_prime(p));

    do {
        q = rand() % limit + 1;
    } while (!is_prime(q));

    *n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        *e = rand() % phi + 1;
    } while (gcd(*e, phi) != 1);

    // Calculate the private key d
    int k = 1;

    while(1){
        k += phi;
        if(k % *e == 0){
            *d = k / *e;
            break;
         }
    }

    return (int) *e * *d % phi == 1;
}

int main(){
    int e, d, n;
    int p = 7;
    int q = 13;
    int plaintext = 88;

    generate_rsa_keys(&e, &d, &n);

    int ciphertext = (int) fmod(pow(plaintext, e), n);
    int decryptedtext = (int) fmod(pow(ciphertext, d), n);

    printf("Public Key (%d, %d)\n", e, n);
    printf("Private Key (%d, %d)\n", d, n);
    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decryptedtext: %d\n", decryptedtext);

    return 0;
}