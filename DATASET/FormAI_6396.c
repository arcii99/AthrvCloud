//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the message using Caesar cipher
char* encryptMessage(char* message, int key) 
{
    int i;
    char* encryptedMessage = (char*) malloc((strlen(message) + 1) * sizeof(char));
    strcpy(encryptedMessage, message);

    for(i = 0; i < strlen(message); i++) 
    {
        if(message[i] >= 'a' && message[i] <= 'z') 
        {
            encryptedMessage[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') 
        {
            encryptedMessage[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }

    return encryptedMessage;
}

int main()
{
    char message[100], *encryptedMessage;
    int key;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();

    printf("Enter key: ");
    scanf("%d", &key);

    encryptedMessage = encryptMessage(message, key);
    printf("Encrypted message: %s", encryptedMessage);

    free(encryptedMessage);
    return 0;
}