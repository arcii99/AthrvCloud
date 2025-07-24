//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <string.h>

/* Function to encrypt a string */
void encrypt(char* str, int key)
{
    int len = strlen(str);
    /* Convert key to a character */
    char keyChar = (char) (key % 256);
    /* Encrypt each character in the string */
    for(int i = 0; i < len; i++)
    {
        str[i] = (char) (((str[i] + keyChar) % 256) + 10);
    }
}

/* Function to decrypt a string */
void decrypt(char* str, int key)
{
    int len = strlen(str);
    /* Convert key to a character */
    char keyChar = (char) (key % 256);
    /* Decrypt each character in the string */
    for(int i = 0; i < len; i++)
    {
        str[i] = (char) (((str[i] - 10 - keyChar + 256) % 256));
    }
}

int main()
{
    int key = 18;
    char message[] = "Ye olde program be the best!";
    printf("Original message: %s\n", message);
    /* Encrypt the message */
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    /* Decrypt the message */
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}