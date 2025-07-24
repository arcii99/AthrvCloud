//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
// Genius-style Unique C Public-Key Algorithm Implementation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b)
{
    while(b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

// Function to generate prime number
int generatePrime()
{
    int num = rand() % 100;
    int i;
    for(i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            break;
        }
    }
    if(i == num)
    {
        return num;
    }
    else
    {
        return generatePrime();
    }
}

// Function to create public and private keys
void createKeys(int *publicKey, int *privateKey)
{
    int p = generatePrime();
    int q = generatePrime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e;
    int d;

    for(e = 2; e < phi; e++)
    {
        if(gcd(e, phi) == 1)
        {
            break;
        }
    }

    int k = 2;
    while(1)
    {
        d = (k * phi + 1) / e;
        if((k * phi + 1) % e == 0)
        {
            break;
        }
        k++;
    }

    *publicKey = e;
    *privateKey = d;
}

// Function to encrypt data using public key
int encryptData(int data, int publicKey, int n)
{
    int encryptedData = pow(data, publicKey);
    encryptedData = encryptedData % n;
    return encryptedData;
}

// Function to decrypt data using private key
int decryptData(int encryptedData, int privateKey, int n)
{
    int decryptedData = pow(encryptedData, privateKey);
    decryptedData = decryptedData % n;
    return decryptedData;
}

// Main function
int main()
{
    int publicKey, privateKey;
    createKeys(&publicKey, &privateKey);

    int data = 1234;
    int n = 3233;

    int encryptedData = encryptData(data, publicKey, n);
    int decryptedData = decryptData(encryptedData, privateKey, n);

    printf("Public key: %d\n", publicKey);
    printf("Private key: %d\n", privateKey);
    printf("Original data: %d\n", data);
    printf("Encrypted data: %d\n", encryptedData);
    printf("Decrypted data: %d\n", decryptedData);

    return 0;
}