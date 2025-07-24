//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() 
{
    srand(time(0));     //seed the random number generator with the current time
    int p = 11, q = 17;  //declare two prime numbers, p and q
    int n = p * q;       //calculate the modulus
    int phi = (p-1) * (q-1);   //calculate Euler's totient function

    //choose a random integer e relatively prime to phi(n)
    int e = rand() % phi;
    while (gcd(e, phi) != 1)
       e = rand() % phi;

    //calculate the modular multiplicative inverse of e modulo phi(n)
    int d;
    int k = 1;
    while (1) {
        k = k + phi;
        if (k % e == 0) {
            d = k/e;
            break;
        }
    }

    //print out the public-key and private-key pairs
    printf("Public-key: (%d,%d)\nPrivate-key: (%d,%d)\n", e, n, d, n);

    return 0;
}