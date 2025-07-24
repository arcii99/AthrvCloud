//FormAI DATASET v1.0 Category: Encryption ; Style: safe
#include<stdio.h>
#include<string.h>

void encrypt(char str[])
{
    int len = strlen(str); //finds the length of the string
    for(int i = 0; i < len; i++)
    {
        str[i] = str[i] + 3; //adds 3 to the ASCII value of each character
    }
}

void decrypt(char str[])
{
    int len = strlen(str); //finds the length of the string
    for(int i = 0; i < len; i++)
    {
        str[i] = str[i] - 3; //subtracts 3 from the ASCII value of each character
    }
}

int main()
{
    char message[100];

    //Encryption process
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    encrypt(message); //calls the encryption function
    printf("Encrypted message: %s\n", message);

    //Decryption process
    decrypt(message); //calls the decryption function
    printf("Decrypted message: %s\n", message);

    return 0;
}