//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to calculate gcd
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

//Function to calculate modulo inverse
int mod_inverse(int a, int b) {
    int m = b, t, q;
    int x0 = 0, x1 = 1;

    if(b == 1) {
        return 0;
    }

    //Apply extended Euclidean Algorithm
    while(a > 1) {
        q = a / b;
        t = b;
        b = a % b;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    //Make sure x1 is postive
    if(x1 < 0) {
        x1 += m;
    }

    return x1;
}

int main() {
    int p, q, n, phi, e, d, i, plaintext, ciphertext;

    //Get input from user
    printf("Enter two prime numbers p and q: ");
    scanf("%d %d", &p, &q);

    //Calculate n and phi(n)
    n = p * q;
    phi = (p - 1) * (q - 1);

    //Find e such that gcd(e, phi(n)) = 1
    printf("Choose a number e such that gcd(e, phi(n)) = 1: ");
    scanf("%d", &e);

    //Calculate d, the modular inverse of e modulo phi(n)
    d = mod_inverse(e, phi);

    //Display public and private keys
    printf("\nPublic key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    //Get plaintext from user
    printf("\nEnter plaintext: ");
    scanf("%d", &plaintext);

    //Encrypt plaintext
    ciphertext = fmod(pow(plaintext, e), n);
    printf("Ciphertext: %d\n", ciphertext);

    //Decrypt ciphertext
    plaintext = fmod(pow(ciphertext, d), n);
    printf("Plaintext: %d\n", plaintext);

    return 0;
}