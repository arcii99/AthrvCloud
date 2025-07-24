//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

/* Function prototypes */
void generateKey(char *key);
void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[100], key[ALPHABET_SIZE + 1];

    /* Get message from user */
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    /* Generate encryption key */
    generateKey(key);

    /* Encrypt message */
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    /* Decrypt message */
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}

/* Function to generate encryption key */
void generateKey(char *key)
{
    int i, j;
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

    /* Randomly shuffle the alphabet */
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        j = rand() % ALPHABET_SIZE;
        char temp = alphabet[i];
        alphabet[i] = alphabet[j];
        alphabet[j] = temp;
    }

    /* Copy shuffled alphabet to key */
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        key[i] = alphabet[i];
    }

    /* Add null terminator to key */
    key[ALPHABET_SIZE] = '\0';
}

/* Function to encrypt message using key */
void encrypt(char *message, char *key)
{
    int i;

    /* Iterate through message */
    for(i = 0; message[i] != '\0'; i++)
    {
        /* If character is a letter, encrypt it using key */
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = key[message[i] - 'a'];
        }
    }
}

/* Function to decrypt message using key */
void decrypt(char *message, char *key)
{
    int i, j;

    /* Iterate through message */
    for(i = 0; message[i] != '\0'; i++)
    {
        /* If character is a letter, decrypt it using key */
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            /* Find index of character in key */
            for(j = 0; key[j] != '\0'; j++)
            {
                if(key[j] == message[i])
                {
                    message[i] = 'a' + j;
                    break;
                }
            }
        }
    }
}