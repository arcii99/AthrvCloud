//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key)
{
    int i = 0;
    while(str[i])
    {
        str[i] = (str[i] + key) % 256;
        i++;
    }
}

void decrypt(char *str, int key)
{
    int i = 0;
    while(str[i])
    {
        str[i] = (str[i] - key + 256) % 256;
        i++;
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character from input
    
    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}