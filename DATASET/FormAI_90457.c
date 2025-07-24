//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gcd(int a, int b)
{
    while (a != 0)
    {
        int c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int inverse(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

int isprime(long int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int rsaEncrypt(int msg, int e, int n)
{
    int c = pow(msg, e);
    c = c % n;
    return c;
}

int rsaDecrypt(int msg, int d, int n)
{
    int m = pow(msg, d);
    m = m % n;
    return m;
}

int main()
{
    int p, q, n, phi, e, d, message, encryptedMessage, decryptedMessage;
    srand(time(0));
    while (1) {
        printf("Enter two prime numbers(p, q): ");
        scanf("%d %d", &p, &q);
        if (isprime(p) && isprime(q))
            break;
        else
            printf("Please enter prime numbers! Try again.\n");
    }
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = rand() % phi;
    while (gcd(phi, e) != 1)
        e = rand() % phi;
    d = inverse(e, phi);
    printf("Public Key (n, e): (%d,%d)\n", n, e);
    printf("Private Key (d): %d\n", d);
    printf("Enter a message to be encrypted (less than %d): ", n);
    scanf("%d", &message);
    encryptedMessage = rsaEncrypt(message, e, n);
    printf("Encrypted message: %d\n", encryptedMessage);
    decryptedMessage = rsaDecrypt(encryptedMessage, d, n);
    printf("Decrypted message: %d\n", decryptedMessage);
    return 0;
}