//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program demonstrates a simple encryption algorithm that replaces each character in the message with a different character based on a key */

char* encrypt(char* msg, int key)
{
    int len = strlen(msg);
    char* encrypted = (char*)malloc(sizeof(char) * len);
    int i;
    for(i = 0; i < len; i++)
    {
        char c = msg[i];
        encrypted[i] = (c + key) % 128; // Shift the ASCII value by the key and wrap around if necessary
    }
    return encrypted;
}

int main()
{
    char* message = "Hello World!";
    int key = 7;
    char* encrypted = encrypt(message, key);
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted);
    free(encrypted);
    return 0;
}