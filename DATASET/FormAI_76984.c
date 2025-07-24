//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Function to find gcd of 2 numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int p = 167, q = 359, //Prime numbers p and q
        n = p*q, //Modulus n
        phi = (p-1)*(q-1), //Euler's Totient function
        e, //Public key e
        d; //Private key d

    //Finding a value for public key e
    for(e=2; e<phi; e++)
    {
        if(gcd(e,phi)==1)
            break;
    }

    //Finding private key d
    for(d=1; d<phi; d++)
    {
        if(((d*e)%phi)==1)
            break;
    }

    printf("Public key (e,n): (%d,%d)\n", e, n);
    printf("Private key (d,n): (%d,%d)\n", d, n);

    //Encryption and Decryption
    int m, c, orig;
    printf("Enter a number to encrypt: ");
    scanf("%d", &m);

    //Encrypting message
    c = (int)pow(m,e)%n;
    printf("Encrypted message is: %d\n", c);

    //Decrypting message
    orig = (int)pow(c,d)%n;
    printf("Decrypted message is: %d\n", orig);

    return 0;
}