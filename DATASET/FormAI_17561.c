//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include<stdio.h>

// Recursive function to find gcd of two numbers
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

// Recursive function to find private key
int findPrivateKey(int e, int phi, int d)
{
    if((e*d)%phi == 1)
        return d;
    else
        return findPrivateKey(e, phi, d+1);
}

int main()
{
    int p = 3, q = 7;
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e = 2;
    int d = 1;

    // Find gcd of e and phi
    while(gcd(e, phi) != 1)
        e++;

    // Find private key d
    d = findPrivateKey(e, phi, d);

    printf("Public Key: ({%d, %d})\n", e, n);
    printf("Private Key: ({%d, %d})\n", d, n);

    return 0;
}