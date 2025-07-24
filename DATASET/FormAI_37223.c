//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate power using recursion
int power(int a, int b, int p)
{
    int res = 1; // Initialize result
    a = a % p; // Update a if it is more than or equal to p
    while (b > 0)
    {
        // If b is odd, multiply a with result
        if (b & 1)
            res = (res*a) % p;

        // b must be even now
        b = b>>1; // b = b/2
        a = (a*a) % p; 
    }
    return res;
}

// Function to find gcd of two integers
int gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

// Main function
int main()
{
    // Generate two prime numbers
    srand(time(NULL)); // Seed the random number generator
    int p = rand() % 100 + 1;
    int q = rand() % 100 + 1;
    while (gcd(p, q) != 1)
    {
        p = rand() % 100 + 1;
        q = rand() % 100 + 1;
    }

    // Calculate n and phi(n)
    int n = p*q;
    int phi = (p-1)*(q-1);

    // Generate public key e
    int e = 2;
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Generate private key d
    int d;
    int k = 1;
    while (1)
    {
        k = k + phi;
        if (k % e == 0)
        {
            d = k/e;
            break;
        }
    }

    // Print the keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Encrypt a message
    char msg[100];
    printf("Enter a message to encrypt (max 100 characters): ");
    fgets(msg, 100, stdin);
    int i;
    printf("Encrypted message: ");
    for (i = 0; msg[i] != '\n' && msg[i] != '\0'; i++)
        printf("%d ", power(msg[i], e, n));
    printf("\n");

    // Decrypt the encrypted message
    char decrypted[100];
    printf("Enter the encrypted message to decrypt: ");
    int enc[100];
    for (i = 0; i < 100; i++) // Initialize enc array to 0
        enc[i] = 0;
    i = 0;
    int num;
    while (scanf("%d", &num) == 1) // Read integers from input
    {
        enc[i] = num;
        i++;
    }
    for (i = 0; enc[i] != 0; i++)
        decrypted[i] = power(enc[i], d, n);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}