//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void) {
    srand(time(NULL));

    int p = 0, q = 0, n = 0, totient_n = 0, e = 0, d = 0, flag = 0;

    // generate two random prime numbers
    while (!flag) {
        p = rand() % 100;
        q = rand() % 100;
        if (p != q && gcd(p, q) == 1) {
            flag = 1;
        }
    }

    // calculate n and totient(n)
    n = p * q;
    totient_n = (p - 1) * (q - 1);

    // choose a public key e such that 1 < e < totient(n) and gcd(e, totient(n)) = 1
    int i = 0;
    while (i <= 2 || gcd(i, totient_n) != 1) {
        i = (rand() % (totient_n - 1)) + 1;
    }
    e = i;

    // calculate private key d such that d*e = 1 (mod totient(n))
    for (i = 1; i < totient_n; i++) {
        if ((e * i) % totient_n == 1) {
            d = i;
            break;
        }
    }

    // test encryption and decryption
    int plaintext = 65; // ASCII code for 'A'
    int ciphertext = (int) fmod(pow(plaintext, e), n);
    int decrypted = (int) fmod(pow(ciphertext, d), n);

    printf("p = %d\nq = %d\nn = %d\ntotient(n) = %d\n", p, q, n, totient_n);
    printf("e = %d\nd = %d\n\n", e, d);
    printf("Plaintext: %d\nCiphertext: %d\nDecrypted: %d\n", plaintext, ciphertext, decrypted);

    return 0;
}