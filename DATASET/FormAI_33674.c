//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>

// function to find the greatest common divisor
int gcd(int a, int b)
{
    if(a == 0)
        return b;

    return gcd(b % a, a);
}

int main()
{
    // Two prime numbers
    int p = 101;
    int q = 103;

    // Computing n
    int n = p*q;

    // Computing euler totient
    int euler_totient = (p-1)*(q-1);

    // Generating random prime number for public key
    int public_key = rand() % (euler_totient-2) + 2;
    while(gcd(public_key, euler_totient) != 1)
    {
        public_key = rand() % (euler_totient-2) + 2;
    }

    // Calculating private key
    int private_key = 0;
    int i = 1;
    while(private_key == 0)
    {
        if((public_key*i) % euler_totient == 1)
            private_key = i;
        i++;
    }

    // Printing public and private key
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);

    return 0;
}