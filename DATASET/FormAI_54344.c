//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Sherlock Holmes
//The Adventure of the Public Key Algorithm
//by Sir Arthur Conan Doyle

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//function to generate a random prime number
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

//function to generate prime numbers p and q
void generatePrimes(int* p, int* q) {
    srand(time(NULL));
    *p = rand() % 100 + 1;
    while (!isPrime(*p)) {
        *p = rand() % 100 + 1;
    }
    *q = rand() % 100 + 1;
    while (!isPrime(*q)) {
        *q = rand() % 100 + 1;
    }
}

//function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

//function to calculate the totient
int totient(int p, int q) {
    return (p - 1) * (q - 1);
}

//function to generate public and private keys
void generateKeys(int* e, int* d, int* n) {
    int p, q, tn, gcd_res;
    generatePrimes(&p, &q);
    *n = p * q;
    tn = totient(p, q);
    *e = rand() % (tn - 2) + 2;
    gcd_res = gcd(*e, tn);
    while (gcd_res != 1) {
        *e = rand() % (tn - 2) + 2;
        gcd_res = gcd(*e, tn);
    }
    int k = 1;
    while (true) {
        if ((k * tn + 1) % *e == 0) {
            *d = (k * tn + 1) / *e;
            break;
        }
        k++;
    }
}

int main() {
    int e, d, n, msg, enc_msg, dec_msg;

    generateKeys(&e, &d, &n);

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    printf("Enter a message to encrypt: ");
    scanf("%d", &msg);

    enc_msg = (int)pow(msg, e) % n;
    printf("Encrypted message: %d\n", enc_msg);

    dec_msg = (int)pow(enc_msg, d) % n;
    printf("Decrypted message: %d\n", dec_msg);

    return 0;
}