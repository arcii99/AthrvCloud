//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// function to generate key pair
void generateKeyPair(int p, int q, int *e, int *d, int *n) {
    int phi = (p - 1) * (q - 1);
    *n = p * q;
    for (*e = 2; *e < phi; *e = *e + 1) {
        if (gcd(*e, phi) == 1) {
            break;
        }
    }
    int k = 0;
    while (1) {
        k = k + phi;
        if (k % *e == 1) {
            *d = k / *e;
            break;
        }
    }
}

// function to encrypt message using public key
int encrypt(int message, int e, int n) {
    return fmod(pow(message, e), n);
}

// function to decrypt message using private key
int decrypt(int cipher, int d, int n) {
    return fmod(pow(cipher, d), n);
}

int main() {
    printf("----- RSA Public-Key Cryptography ----- \n\n");

    // taking input for prime numbers
    int p, q;
    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);

    // checking if the numbers are prime or not
    int i, flag1 = 1, flag2 = 1;
    for (i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            flag1 = 0;
            break;
        }
    }
    for (i = 2; i <= sqrt(q); i++) {
        if (q % i == 0) {
            flag2 = 0;
            break;
        }
    }
    if (flag1 == 0 || flag2 == 0) {
        printf("\nInvalid Input! Both numbers must be prime.\n");
        exit(0);
    }

    // generating key pair
    int e, d, n;
    generateKeyPair(p, q, &e, &d, &n);
    printf("\nPublic Key (e, n): (%d, %d)\nPrivate Key (d, n): (%d, %d)\n", e, n, d, n);

    // taking input message to be encrypted
    int message;
    printf("\nEnter message to be encrypted (less than %d): ", n);
    scanf("%d", &message);

    // encrypting message
    int cipher = encrypt(message, e, n);
    printf("\nEncrypted Cipher: %d\n", cipher);

    // decrypting cipher
    int decrypted = decrypt(cipher, d, n);
    printf("\nDecrypted Message: %d\n\n", decrypted);

    return 0;
}