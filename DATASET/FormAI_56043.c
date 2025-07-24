//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int generatePublicKey(int p, int q)
{
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;

    while (e < phi)
    {
        if(gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    return e;
}

int generatePrivateKey(int p, int q, int e)
{
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int d = 1;

    while((d * e) % phi != 1 || d == e)
    {
        d++;
    }

    return d;
}

int main()
{
    int p = 11;
    int q = 7;
    int e, d;
    int message = 123;
    int cipher, decrypted;

    e = generatePublicKey(p, q);
    d = generatePrivateKey(p, q, e);

    // Encryption
    cipher = (int) pow(message, e) % (p * q);

    // Decryption
    decrypted = (int) pow(cipher, d) % (p * q);

    printf("Public Key: (%d, %d)\n", e, p*q);
    printf("Private Key: (%d, %d)\n", d, p*q);
    printf("Original Message: %d\n", message);
    printf("Encrypted Message: %d\n", cipher);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}