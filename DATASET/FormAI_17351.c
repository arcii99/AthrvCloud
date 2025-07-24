//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Find GCD of two numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Generate a random prime number
int generatePrime()
{
    int num;
    srand(time(NULL));
    num = rand() % 100 + 1;
    while (1)
    {
        if (num <= 1)
        {
            num = rand() % 100 + 1;
            continue;
        }
        int flag = 0;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return num;
        else
        {
            num = rand() % 100 + 1;
            continue;
        }
    }
}

int main()
{
    int p, q, n, e, d, plaintext, ciphertext, decrypted_text;

    // Generate two random prime numbers
    p = generatePrime();
    q = generatePrime();

    // Calculate modulus
    n = p * q;

    // Calculate totient
    int totient = (p - 1) * (q - 1);

    // Find e such that gcd(e, totient) = 1
    for (e = 2; e < totient; e++)
    {
        if (gcd(e, totient) == 1)
            break;
    }

    // Calculate d such that (d*e) % totient = 1
    for (d = 1; d < totient; d++)
    {
        if (((d * e) % totient) == 1)
            break;
    }

    // Get plaintext from user
    printf("Enter a number to encrypt: ");
    scanf("%d", &plaintext);

    // Encrypt plaintext using public key (e, n)
    ciphertext = pow(plaintext, e);
    ciphertext = ciphertext % n;

    printf("Encrypted text: %d\n", ciphertext);

    // Decrypt ciphertext using private key (d, n)
    decrypted_text = pow(ciphertext, d);
    decrypted_text = decrypted_text % n;

    printf("Decrypted text: %d\n", decrypted_text);

    return 0;
}