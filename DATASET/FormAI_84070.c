//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the gcd of two numbers
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

// Function to generate a random prime number
int generatePrime(int n)
{
    int i, j, flag;
    for(i=n+1;;i++)
    {
        flag = 1;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            return i;
    }
}

// Function to calculate the public key
int calculatePublicKey(int prime1, int prime2)
{
    int phi = (prime1-1)*(prime2-1);
    int publicKey, i;
    for(i=2;i<phi;i++)
    {
        if(gcd(i,phi)==1)
        {
            publicKey = i;
            break;
        }
    }
    return publicKey;
}

// Function to calculate the private key
int calculatePrivateKey(int publicKey, int prime1, int prime2)
{
    int phi = (prime1-1)*(prime2-1);
    int privateKey, i;
    for(i=1;i<phi;i++)
    {
        if((publicKey*i)%phi == 1)
        {
            privateKey = i;
            break;
        }
    }
    return privateKey;
}

// Function to encrypt the message
int encrypt(int message, int publicKey, int prime1, int prime2)
{
    int n = prime1 * prime2;
    int ciphertext = 1, i;
    for(i=0;i<publicKey;i++)
    {
        ciphertext = (ciphertext * message) % n;
    }
    return ciphertext;
}

// Function to decrypt the message
int decrypt(int ciphertext, int privateKey, int prime1, int prime2)
{
    int n = prime1 * prime2;
    int plaintext = 1, i;
    for(i=0;i<privateKey;i++)
    {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main()
{
    int prime1, prime2, publicKey, privateKey, message, ciphertext, plaintext;
    prime1 = generatePrime(100);
    prime2 = generatePrime(prime1);
    publicKey = calculatePublicKey(prime1, prime2);
    privateKey = calculatePrivateKey(publicKey, prime1, prime2);
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);
    ciphertext = encrypt(message, publicKey, prime1, prime2);
    printf("\nEncrypted Message: %d", ciphertext);
    plaintext = decrypt(ciphertext, privateKey, prime1, prime2);
    printf("\nDecrypted Message: %d", plaintext);
    return 0;
}