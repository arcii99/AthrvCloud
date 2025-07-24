//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function to calculate modular exponentiation a^b mod m.
int mod_exp(int base, int exp, int modulus)
{
    int result = 1;

    while (exp > 0)
    {
        // If exponent is odd.
        if (exp % 2 == 1)
            result = (result * base) % modulus;
        
        // Square the base and divide the exponent by 2.
        base = (base * base) % modulus;
        exp = exp / 2;
    }

    return result;
}

// Function to generate a random prime number between range (a, b).
int rand_prime(int a, int b)
{
    int n;

    // Keep generating random numbers until a prime number is generated.
    while (1)
    {
        n = rand() % (b - a + 1) + a;

        // Check if the number is prime.
        int flag = 1;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }

    return n;
}

// Function to find Greatest Common Divisor (GCD) of two numbers.
int gcd(int a, int b) 
{
    int temp;
    while (1)
    {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

int main()
{
    int p, q, n, phi, e, d, message, cipher, decrypted_message;

    // Generate two distinct prime numbers p and q randomly.
    srand(time(NULL));
    p = rand_prime(1000, 9999);
    q = rand_prime(1000, 9999);
    while (p == q)
    {
        q = rand_prime(1000, 9999);
    }

    // Calculate modulus n and Euler's totient phi.
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1.
    e = rand_prime(2, phi-1);
    while (gcd(e, phi) != 1)
    {
        e = rand_prime(2, phi-1);
    }

    // Calculate d such that e*d mod phi = 1.
    int k = 1;
    while (1)
    {
        if (((k * phi) + 1) % e == 0)
        {
            d = ((k * phi) + 1) / e;
            break;
        }
        k++;
    }

    // Get the message to be encrypted.
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);

    // Encrypt the message using public key (e, n).
    cipher = mod_exp(message, e, n);
    printf("Encrypted message: %d\n", cipher);

    // Decrypt the message using private key (d, n).
    decrypted_message = mod_exp(cipher, d, n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}