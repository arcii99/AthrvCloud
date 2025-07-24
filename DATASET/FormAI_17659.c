//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to calculate GCD of two numbers
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

//Function to find the modular inverse of a number
int modInverse(int a, int m)
{
    a = a % m;
    for(int x = 1; x < m; x++)
    {
        if((a * x) % m == 1)
        {
            return x;
        }
    }
    return -1;
}

//Main function
int main()
{
    int p = 17, q = 11; //Prime numbers chosen for generating the keys
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 7; //Public key
    int d = modInverse(e, phi); //Private key

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    //Encryption process
    char message[100];
    printf("\nEnter the message to encrypt: ");
    scanf("%s", message);
    int len = strlen(message);

    int encryptedMessage[len];
    for(int i = 0; i < len; i++)
    {
        encryptedMessage[i] = (int)message[i];
        encryptedMessage[i] = (encryptedMessage[i] * encryptedMessage[i]) % n;
    }

    printf("Cipher text: ");
    for(int i = 0; i < len; i++)
    {
        printf("%d ", encryptedMessage[i]);
    }

    //Decryption process
    char decryptedMessage[len];
    for(int i = 0; i < len; i++)
    {
        int temp = (encryptedMessage[i] * d) % n;
        decryptedMessage[i] = (char)((temp * modInverse(encryptedMessage[i], n)) % n);
    }

    printf("\nDecrypted message: %s\n", decryptedMessage);

    return 0;
}