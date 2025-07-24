//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generate_keys(int p, int q, int* n, int* phi_n, int* e, int* d);
int gcd(int a, int b);
int mod_inverse(int a, int m);
int encrypt(int msg, int e, int n);
int decrypt(int cipher, int d, int n);

int main() {

    srand(time(NULL)); // set random seed

    int p = 7; // choose prime p
    int q = 11; // choose prime q
    int n, phi_n, e, d;

    generate_keys(p, q, &n, &phi_n, &e, &d); // generate public and private keys

    int msg = 200; // message to be encrypted
    int cipher = encrypt(msg, e, n); // encrypt message
    int decrypted_msg = decrypt(cipher, d, n); // decrypt message

    printf("Original Message: %d\nEncrypted Message: %d\nDecrypted Message: %d\n", msg, cipher, decrypted_msg);
    return 0;
}

void generate_keys(int p, int q, int* n, int* phi_n, int* e, int* d) {

    *n = p*q; // calculate n
    *phi_n = (p-1)*(q-1); // calculate phi(n)

    // choose e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    do {
        *e = rand() % (*phi_n-1) + 2; 
    } while (gcd(*e, *phi_n) != 1);

    // calculate d such that d is the modular inverse of e with respect to phi(n)
    *d = mod_inverse(*e, *phi_n);
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int encrypt(int msg, int e, int n) {
    return (int)pow(msg, e) % n; // use modular exponentiation to encrypt message
}

int decrypt(int cipher, int d, int n) {
    return (int)pow(cipher, d) % n; // use modular exponentiation to decrypt message
}