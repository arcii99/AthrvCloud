//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Function to find greatest common divisor between two numbers
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate inverse of a number
int modInverse(int a, int m)
{
    int m0 = m;
    int y=0, x=1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

int main()
{
    srand((unsigned int) time(NULL));

    int p, q, n, phi, e, d, msg, cipher;

    // generate two random prime numbers
    do {
        p = rand() % 100 + 1;
    } while (p == 1 || p == 2);
    do {
        q = rand() % 100 + 1;
    } while (q == 1 || q == 2 || q == p);

    // calculate n
    n = p * q;

    // calculate totient(n)
    phi = (p - 1) * (q - 1);

    // generate public key e
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);

    // generate private key d
    d = modInverse(e, phi);

    // get message from user
    printf("Enter the message: ");
    scanf("%d", &msg);

    // encrypt the message using public key
    cipher = pow(msg, e);
    cipher = fmod(cipher, n);

    // decrypt the message using private key
    msg = pow(cipher, d);
    msg = fmod(msg, n);

    // print encrypted and decrypted messages
    printf("Encrypted message: %d\n", cipher);
    printf("Decrypted message: %d\n", msg);

    return 0;
}