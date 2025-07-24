//FormAI DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
void encrypt(char[], int);
void decrypt(char[], int);

int main()
{
    char message[50];
    int key;

    printf("My love, please enter your message: ");
    scanf("%s", message);

    printf("\nMy love, please enter your secret key (integer): ");
    scanf("%d", &key);

    printf("\nPerforming encryption...\n");

    encrypt(message, key);
    printf("\nMessage after encryption: %s\n", message);

    printf("\nPerforming decryption...\n");

    decrypt(message, key);
    printf("\nMessage after decryption: %s\n", message);

    printf("\nMy love, our secret message is safe now!\n");

    return 0;
}

// Function definition for encryption
void encrypt(char message[], int key)
{
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {
        // Adding key to ASCII value of each character in the message
        message[i] = ((message[i] + key) % 127) + 1;
    }
}

// Function definition for decryption
void decrypt(char message[], int key)
{
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {
        // Subtracting key from ASCII value of each character in the message
        message[i] = ((message[i] - key - 1) % 127);

        // If the result is less than 0, adding 127 to get a valid ASCII value
        if (message[i] < 0)
        {
            message[i] += 127;
        }
    }
}