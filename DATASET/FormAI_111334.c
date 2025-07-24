//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to calculate the gcd of two numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// function to generate the public and private keys
void generateKeys(int p, int q, int *n, int *e, int *d)
{
    // calculate n
    *n = p * q;

    // calculate totient
    int totient = (p - 1) * (q - 1);

    // find e such that e and totient are coprime
    *e = rand() % totient;
    while (gcd(*e, totient) != 1) {
        *e = rand() % totient;
    }

    // calculate d such that d*e = 1 mod (totient)
    int k = 1;
    while (1) {
        int temp = (k*totient) + 1;
        if (temp % *e == 0) {
            *d = temp / *e;
            break;
        }
        k++;
    }
}

// function to encrypt a message
void encrypt(int n, int e, char *message, int *result)
{
    for (int i = 0; i < strlen(message); i++) {
        // convert the ith character to an integer
        int x = message[i] - 'a';

        // encrypt x using the public key (n,e)
        int y = 1;
        for (int j = 0; j < e; j++) {
            y = (y * x) % n;
        }

        // store the result in the ith element of the result array
        result[i] = y;
    }
}

// function to decrypt a message
void decrypt(int n, int d, int *encrypted, char *result)
{
    for (int i = 0; i < strlen(encrypted); i++) {
        // decrypt the ith element of the encrypted array using the private key (n,d)
        int x = encrypted[i];

        int y = 1;
        for (int j = 0; j < d; j++) {
            y = (y * x) % n;
        }

        // convert y back to a character and store it in the ith element of the result array
        result[i] = (char) (y + 'a');
    }
}

int main()
{
    int p = 17, q = 19;
    int n, e, d;

    generateKeys(p, q, &n, &e, &d);

    printf("Public Key (n,e): (%d,%d)\n", n, e);
    printf("Private Key (n,d): (%d,%d)\n", n, d);

    char message[] = "hello world";
    int encrypted[strlen(message)];
    encrypt(n, e, message, encrypted);
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%d ", encrypted[i]);
    }

    char decrypted[strlen(message)];
    decrypt(n, d, encrypted, decrypted);
    printf("\nDecrypted message: %s\n", decrypted);

    return 0;
}