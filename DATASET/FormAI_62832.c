//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char *str, int key);

int main()
{
    char message[] = "This is a secret message!";
    int key = 3;

    printf("Original Message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    return 0;
}

void encrypt(char *str, int key)
{
    while (*str) // Loop through each character in the string
    {
        if (isalpha(*str)) // Check if character is alphabetical
        {
            if (isupper(*str)) // Check if character is uppercase
            {
                *str = (((*str - 'A') + key) % 26) + 'A'; // Apply Caesar Cipher formula for uppercase letters
            }
            else // Character is lowercase
            {
                *str = (((*str - 'a') + key) % 26) + 'a'; // Apply Caesar Cipher formula for lowercase letters
            }
        }
        str++; // Move to next character in string
    }
}