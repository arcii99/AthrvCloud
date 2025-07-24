//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], char password[])
{
    int len_message = strlen(message);
    int len_password = strlen(password);
    
    for (int i = 0; i < len_message; i++)
    {
        message[i] = message[i] + password[i % len_password];
    }
}

void decrypt(char message[], char password[])
{
    int len_message = strlen(message);
    int len_password = strlen(password);
    
    for (int i = 0; i < len_message; i++)
    {
        message[i] = message[i] - password[i % len_password];
    }
}

int main()
{
    char message[100];
    char password[100];
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    
    printf("Enter password: ");
    fgets(password, 100, stdin);
    
    encrypt(message, password);
    
    printf("\nEncrypted message: %s\n", message);
    
    decrypt(message, password);
    
    printf("\nDecrypted message: %s\n", message);
    
    return 0;
}