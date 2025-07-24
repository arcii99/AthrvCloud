//FormAI DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char* str, int key)
{
    int len = strlen(str);
    char* encrypted = (char*) malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        encrypted[i] = str[i] ^ key;
    }
    encrypted[len] = '\0';
    return encrypted;
}

int main()
{
    char* msg = "Hello, world!";
    int key = 23;
    char* encrypted = encrypt(msg, key);
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted);
    return 0;
}