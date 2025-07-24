//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
// This program demonstrates an implementation of a public key algorithm similar to the RSA algorithm
// developed by Claude Shannon, the father of modern cryptography.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isprime(int n)
{
    int i;
    for(i=2;i<sqrt(n);i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int gcd(int a, int b) 
{
   if (a == 0) 
      return b;
   return gcd(b%a, a);
}

int main()
{
    int p, q, n, e, d, phi, m, c, plaintext;
    printf("Enter two prime numbers p, q such that p ≠ q: ");
    scanf("%d %d",&p, &q);
    n = p*q;
    phi = (p-1)*(q-1);

    // Find an integer e that is relatively prime to phi(n)
    for (e=2; e<phi; e++) 
    {
        if (gcd(e, phi) == 1)
            break;
    }

    // Find the multiplicative inverse d of e modulo phi(n)
    int k = 1;
    while (1) 
    {
        k += phi;
        if (k % e == 0) 
        {
            d = k/e;
            break;
        }
    }

    // Encryption
    printf("\nEnter message to be encrypted (integer): ");
    scanf("%d", &plaintext);
    c = pow(plaintext, e);
    c = c % n;
    printf("\nEncrypted message: %d", c);

    // Decryption
    m = pow(c, d);
    m = m % n;
    printf("\nDecrypted message: %d\n", m);

    return 0;
}