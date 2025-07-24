//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

const int MAX = 100; //The maximum number of characters to be encrypted/decrypted at once
const int SHIFT = 3; //The number of positions to shift each character

//Function prototype declarations
void encrypt(char[], char[]);
void decrypt(char[], char[]);

//Main function
int main()
{
    char message[MAX]; //To hold the original message
    char encrypted[MAX]; //To hold the encrypted message
    char decrypted[MAX]; //To hold the decrypted message

    srand(time(0)); //Seed the random number generator

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX, stdin); //Read in the message

    printf("\nEncrypting message...\n");
    encrypt(message, encrypted); //Encrypt the message

    printf("Encrypted message: %s\n", encrypted); //Print the encrypted message
    printf("\nDecrypting message...\n");
    decrypt(encrypted, decrypted); //Decrypt the message

    printf("Decrypted message: %s\n", decrypted); //Print the decrypted message

    return 0;
}

//Function to encrypt a message
void encrypt(char message[], char encrypted[])
{
    int i, len;

    len = strlen(message); //Get the length of the message

    for(i = 0; i < len; i++)
    {
        if((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z'))
        {
            encrypted[i] = message[i] + SHIFT; //Shift the character by SHIFT positions
            if(encrypted[i] > 'z') //If the character is shifted beyond 'z'
            {
                encrypted[i] = encrypted[i] - 26; //Wrap around to 'a'
            }
            if(encrypted[i] > 'Z' && encrypted[i] < 'a') //If the character is not an alphabet
            {
                encrypted[i] = encrypted[i] - SHIFT; //Reverse the shift
            }

            //Generate a random number between 0 and 9
            int random = rand() % 10;

            //XOR the character with the random number
            encrypted[i] = encrypted[i] ^ random;
        }
        else //If the character is not an alphabet
        {
            encrypted[i] = message[i]; //Copy the character as it is
        }
    }

    encrypted[len] = '\0'; //Add the null terminator at the end
}

//Function to decrypt a message
void decrypt(char encrypted[], char decrypted[])
{
    int i, len;

    len = strlen(encrypted); //Get the length of the encrypted message

    for(i = 0; i < len; i++)
    {
        if((encrypted[i] >= 'a' && encrypted[i] <= 'z') || (encrypted[i] >= 'A' && encrypted[i] <= 'Z'))
        {
            //XOR the character with the same random number as before
            int random = rand() % 10;
            char temp = encrypted[i] ^ random;

            temp = temp - SHIFT; //Reverse the shift to get the original character

            if(temp < 'A') //If the character is shifted beyond 'A'
            {
                temp = temp + 26; //Wrap around to 'Z'
            }
            if(temp > 'Z' && temp < 'a') //If the character is not an alphabet
            {
                temp = temp + SHIFT; //Reverse the reverse shift
            }

            decrypted[i] = temp;
        }
        else //If the character is not an alphabet
        {
            decrypted[i] = encrypted[i]; //Copy the character as it is
        }
    }

    decrypted[len] = '\0'; //Add the null terminator at the end
}