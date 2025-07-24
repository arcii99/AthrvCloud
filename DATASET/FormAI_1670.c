//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//function to find the greatest common divisor of two numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//function to generate a prime number
int generatePrime()
{
    int i, j, flag;
    srand(time(NULL));
    int numbers[1000] = {0};
    int primeNumbers[100] = {0};
    int count = 0;

    for (i = 2; i < 1000; i++)
    {
        flag = 0;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        //if a number is prime, add it to the array of prime numbers
        if (flag == 0)
        {
            numbers[i] = 1;
            primeNumbers[count] = i;
            count++;
        }
    }
    //select a random prime number from the array of prime numbers
    int index = rand() % count;
    return primeNumbers[index];
}

//function to generate a public and private key
void generateKeys(int p, int q, int *publicKey, int *privateKey)
{
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e, d;

    //select a random number e that is coprime with phi(n)
    do
    {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    //calculate d as the modular multiplicative inverse of e mod phi(n)
    int k = 1;
    while ((1 + k * phi) % e != 0)
    {
        k++;
    }
    d = (1 + k * phi) / e;

    //set the public and private keys
    *publicKey = e;
    *privateKey = d;
}

//function to encrypt a message using a public key
int *encrypt(char *message, int messageLength, int publicKey, int n)
{
    int *encryptedMessage = (int *)malloc(sizeof(int) * messageLength);
    int i;

    //encrypt each character of the message using the public key
    for (i = 0; i < messageLength; i++)
    {
        encryptedMessage[i] = (int)message[i];
        encryptedMessage[i] = (int)(pow(encryptedMessage[i], publicKey)) % n;
    }

    return encryptedMessage;
}

//function to decrypt a message using a private key
char *decrypt(int *encryptedMessage, int messageLength, int privateKey, int n)
{
    char *decryptedMessage = (char *)malloc(sizeof(char) * messageLength);
    int i;

    //decrypt each character of the message using the private key
    for (i = 0; i < messageLength; i++)
    {
        decryptedMessage[i] = encryptedMessage[i];
        decryptedMessage[i] = (char)(pow(decryptedMessage[i], privateKey)) % n;
    }

    return decryptedMessage;
}

int main()
{
    int p, q, publicKey, privateKey, i, messageLength;
    char message[1000] = "";

    //generate two prime numbers
    p = generatePrime();
    q = generatePrime();

    //generate public and private key
    generateKeys(p, q, &publicKey, &privateKey);

    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);

    //remove newline character from message
    messageLength = strlen(message) - 1;
    if (message[messageLength] == '\n')
    {
        message[messageLength] = '\0';
        messageLength--;
    }

    //encrypt message using public key
    int *encryptedMessage = encrypt(message, messageLength, publicKey, p * q);

    //output encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < messageLength; i++)
    {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");

    //decrypt message using private key
    char *decryptedMessage = decrypt(encryptedMessage, messageLength, privateKey, p * q);

    //output decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    //free memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}