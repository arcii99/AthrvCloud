//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void generateKey(int p, int q, int *e, int *d, int *n)
{
    *n = p * q;

    int phi = (p - 1) * (q - 1);

    for (*e = 2; *e < phi; (*e)++)
    {
        if (gcd(*e, phi) == 1)
            break;
    }

    for (*d = 1; *d < phi; (*d)++)
    {
        if (((*d) * (*e)) % phi == 1)
            break;
    }
}

int encryptChar(char c, int e, int n)
{
    int result = c;

    for (int i = 1; i < e; i++)
        result = (result * c) % n;

    return result;
}

char decryptChar(int c, int d, int n)
{
    int result = c;

    for (int i = 1; i < d; i++)
        result = (result * c) % n;

    return result;
}

bool testEncryptionDecryption(int p, int q)
{
    int e, d, n;
    generateKey(p, q, &e, &d, &n);

    char testChar = 'A';
    int encrypted = encryptChar(testChar, e, n);
    char decrypted = decryptChar(encrypted, d, n);

    return decrypted == testChar;
}

int main()
{
    int p = 11;
    int q = 17;

    // Test encryption and decryption
    if (testEncryptionDecryption(p, q))
        printf("Encryption and decryption works\n");
    else
    {
        printf("Encryption and decryption do not work\n");
        return -1;
    }

    // Generate keys
    int e, d, n;
    generateKey(p, q, &e, &d, &n);

    // Print keys and encrypted message
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Encrypt message
    char message[20] = "HELLO WORLD";
    printf("Original message: %s\n", message);

    int encrypted[20];
    for (int i = 0; i < 20; i++)
        encrypted[i] = encryptChar(message[i], e, n);

    printf("Encrypted message:\n");
    for (int i = 0; i < 20; i++)
        printf("%d ", encrypted[i]);
    printf("\n");

    // Decrypt message
    char decrypted[20];
    for (int i = 0; i < 20; i++)
        decrypted[i] = decryptChar(encrypted[i], d, n);

    decrypted[20] = '\0';

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}