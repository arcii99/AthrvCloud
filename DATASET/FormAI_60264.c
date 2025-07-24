//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int p, q, n, phi, e, d, plaintext, ciphertext;
    printf("Enter two distinct prime numbers: ");
    scanf("%d %d", &p, &q);

    // Calculate n and phi(n)
    n = p*q;
    phi = (p-1)*(q-1);

    // Find an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    for(e=2; e<phi; e++)
    {
        if(gcd(e, phi) == 1)
            break;
    }

    // Find d such that d ≡ e⁻¹ (mod φ(n))
    // This is equivalent to solving the linear congruence ax ≡ b (mod m) for x.
    int a = e;
    int b = 1;
    int m = phi;
    int x = 0, y = 0;
    int g = 0;
    int n1 = 0, n2 = 0;
    int q1 = 0, q2 = 0;

    if (m == 1)
    {
        d = 0;
    }
    else
    {
        n1 = 1;
        n2 = 0;
        q1 = 0;
        q2 = 0;

        while (a > 0)
        {
            q1 = m / a;
            n1 -= q1 * x;
            n2 -= q1 * y;
            m -= q1 * a;

            g = x;
            x = y;
            y = g;

            q2 = a;
            a = m;
            m = q2;
        }

        d = n1 + phi;
    }

    printf("Public key: (%d,%d)\n", e, n);
    printf("Private key: (%d,%d)\n", d, n);

    // Encryption
    printf("\nEnter plaintext (integer): ");
    scanf("%d", &plaintext);
    ciphertext = fmod(pow(plaintext, e), n);
    printf("Ciphertext: %d", ciphertext);

    // Decryption
    plaintext = fmod(pow(ciphertext, d), n);
    printf("\nDecrypted plaintext: %d", plaintext);
    return 0;
}