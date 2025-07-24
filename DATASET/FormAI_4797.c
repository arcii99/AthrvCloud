//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Get the greatest common divisor of two integers
int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// Check whether a number is prime or not
bool is_prime(int num) {
    int i;
    if (num <= 1) {
        return false;
    }
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Generate a random prime number in the given range
int generate_prime(int min, int max) {
    int num;
    while (true) {
        num = rand() % (max - min + 1) + min;
        if (is_prime(num)) {
            return num;
        }
    }
}

// Generate the public and private keys
void generate_keys(int *p, int *q, int *n, int *e, int *d) {
    *p = generate_prime(1000, 5000);
    *q = generate_prime(5000, 10000);
    *n = *p * *q;
    int phi = (*p - 1) * (*q - 1);
    do {
        *e = rand() % phi + 1;
    } while (gcd(*e, phi) != 1);
    int k = 1;
    while ((k * phi + 1) % *e != 0) {
        k++;
    }
    *d = (k * phi + 1) / *e;
}

// Encrypt the text message using the public key
int *encrypt(int *msg, int len, int n, int e) {
    int *cipher = malloc(len * sizeof(int));
    int i;
    for (i = 0; i < len; i++) {
        int m = msg[i];
        int c = 1;
        int j;
        for (j = 1; j <= e; j++) {
            c = (c * m) % n;
        }
        cipher[i] = c;
    }
    return cipher;
}

// Decrypt the cipher text using the private key
int *decrypt(int *cipher, int len, int n, int d) {
    int *msg = malloc(len * sizeof(int));
    int i;
    for (i = 0; i < len; i++) {
        int c = cipher[i];
        int m = 1;
        int j;
        for (j = 1; j <= d; j++) {
            m = (m * c) % n;
        }
        msg[i] = m;
    }
    return msg;
}

int main() {
    int p, q, n, e, d;
    generate_keys(&p, &q, &n, &e, &d);
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d)\n", d);

    int msg[] = { 65, 66, 67 }; // ASCII codes of "ABC"
    int len = sizeof(msg) / sizeof(int);
    printf("Original message: ");
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", (char)msg[i]);
    }
    printf("\n");

    int *cipher = encrypt(msg, len, n, e);
    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%d ", cipher[i]);
    }
    printf("\n");

    int *decrypted_msg = decrypt(cipher, len, n, d);
    printf("Decrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", (char)decrypted_msg[i]);
    }
    printf("\n");

    free(cipher);
    free(decrypted_msg);
    return 0;
}