//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Encrypt(char* message, int key)
{
    char* encrypted_message = (char*)malloc(strlen(message) * sizeof(char));
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        encrypted_message[i] = message[i] + key;
    }
    encrypted_message[i] = '\0';
    return encrypted_message;    
}

char* Decrypt(char* encrypted_message, int key)
{
    char* message = (char*)malloc(strlen(encrypted_message) * sizeof(char));
    int i;
    for(i = 0; i < strlen(encrypted_message); i++)
    {
        message[i] = encrypted_message[i] - key; 
    }
    message[i] = '\0';
    return message;
}

int main()
{
    char* message = "Hello Cryptic!";
    int key = 5;
    char* encrypted_message = Encrypt(message, key);
    printf("Encrypted Message: %s\n", encrypted_message);
    char* decrypted_message = Decrypt(encrypted_message, key);
    printf("Decrypted Message: %s\n", decrypted_message);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}