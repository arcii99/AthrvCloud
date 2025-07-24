//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long int gcd(long int a, long int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    long int p, q, n, phi, e, d, message, ciphertext, decrypted_message;
    srand(time(0));
    p = rand() % 1000 + 1; // generate a random prime number
    q = rand() % 1000 + 1; // generate a different random prime number
    while (gcd(p, q) != 1) // check if p and q are coprime
    {
        p = rand() % 1000 + 1;
        q = rand() % 1000 + 1;
    }
    n = p * q; // compute modulus
    phi = (p - 1) * (q - 1); // compute Euler's totient function
    e = 2; // choose a prime number less than phi
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    d = 1;
    while ((d * e) % phi != 1)
        d++; // compute the modular multiplicative inverse of e
    printf("Public key: (%li, %li)\nPrivate key: (%li, %li)\n", e, n, d, n);
    message = rand() % 1000 + 1; // generate a random message
    printf("Message: %li\n", message);
    ciphertext = fmod(pow(message, e), n); // compute ciphertext
    printf("Ciphertext: %li\n", ciphertext);
    decrypted_message = fmod(pow(ciphertext, d), n); // compute decrypted message
    printf("Decrypted message: %li\n", decrypted_message);
    return 0;
}