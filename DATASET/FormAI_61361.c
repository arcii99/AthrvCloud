//FormAI DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "ThisIsSecretKey"

void encrypt(char* message)
{
    int len = strlen(message);
    int keyLen = strlen(KEY);
    char newKey[len], encryptedMsg[len];
    
    // Create new key
    int i, j;
    for(i = 0, j = 0; i < len; ++i, ++j){
        if(j == keyLen) j = 0;
        newKey[i] = KEY[j];
    }
    newKey[len] = '\0';

    // Encrypt message
    for(i = 0; i < len; ++i)
        encryptedMsg[i] = message[i] ^ newKey[i];
    encryptedMsg[len] = '\0';

    // Print result
    printf("\nOriginal Message: %s", message);
    printf("\nEncrypted Message: %s", encryptedMsg);
}

int main()
{
    char message[100];

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove trailing newline char
    int len = strlen(message);
    if(message[len-1] == '\n')
        message[len-1] = '\0';

    // Encrypt message
    encrypt(message);

    return 0;
}