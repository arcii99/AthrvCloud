//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character
char encryptChar(char ch, int key)
{
    return ((ch + key - 97) % 26) + 97;
}

// Function to encrypt a string
char* encryptString(char *str, int key)
{
    int len = strlen(str);
    char *encryptedStr = (char*) malloc(sizeof(char) * (len + 1));

    for(int i = 0; i < len; i++)
    {
        encryptedStr[i] = encryptChar(str[i], key);
    }

    encryptedStr[len] = '\0';

    return encryptedStr;
}

int main()
{
    char str[] = "Hello World";
    int key = 10;

    char *encryptedStr = encryptString(str, key);

    printf("Original String: %s\n", str);
    printf("Encrypted String: %s\n", encryptedStr);

    free(encryptedStr);

    return 0;
}