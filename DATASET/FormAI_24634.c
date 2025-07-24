//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int p, q, n, phi, e, d, m, c, decrypted;

    // Step 1: Generate two prime numbers
    p = 3;
    q = 5;

    // Step 2: Calculate modulus n and totient of n
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Step 3: Choose a number e that is coprime to phi and calculate d
    e = 7;
    while (1) {
        if ((e * phi + 1) % n == 0) {
            d = (e * phi + 1) / n;
            break;
        }
        e++;
    }

    // display public and private keys
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // encryption
    printf("\nEnter message to be encrypted: ");
    scanf("%d", &m);
    c = pow(m, e);
    c %= n;
    printf("Encrypted message: %d\n", c);

    // decryption
    decrypted = pow(c, d);
    decrypted %= n;
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}