//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: invasive
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//Function to find GCD of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int p, q, n, phi, e=2, d, plaintext, ciphertext;
    
    srand(time(0));
    
    //Generating two random prime numbers
    do {
        p = rand() % 1000;
    } while (p <= 1 || p >= 1000);
    
    do {
        q = rand() % 1000;
    } while (q <= 1 || q >= 1000 || q==p);
    
    //Calculating n and phi(n)
    n = p * q;
    phi = (p-1) * (q-1);
    
    //Choosing e such that gcd(e, phi(n)) is 1
    while(gcd(e, phi) != 1)
    {
        e++;
    }
    
    //Calculating d such that d is the inverse of e modulo phi(n)
    int k = 1;
    while(1)
    {
        d = (1 + (k * phi)) / e;
        if ((1 + (k * phi)) % e == 0)
            break;
        k++;
    }
    
    //Printing the public key
    printf("Public Key: (%d, %d)\n", e, n);
    
    //Printing the private key
    printf("Private Key: (%d, %d)\n", d, n);
    
    //Getting the plaintext from user and encrypting it
    printf("Enter the plaintext: ");
    scanf("%d", &plaintext);
    ciphertext = fmod(pow(plaintext, e), n);
    printf("Encrypted Message: %d\n", ciphertext);
    
    //Decrypting the ciphertext and printing the original message
    plaintext = fmod(pow(ciphertext, d), n);
    printf("Decrypted Message: %d\n", plaintext);
    
    return 0;
}