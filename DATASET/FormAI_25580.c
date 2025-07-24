//FormAI DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100]; // Message to encrypt
    char key[10]; // Encryption key
    int keyLength, messageLength, i, j;
    int encryptedMessage[100];
    int asciiValue;
    
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    messageLength = strlen(message);
    
    printf("Enter an encryption key (up to 10 characters): ");
    fgets(key, sizeof(key), stdin);
    keyLength = strlen(key);
    
    // Loop through each character in the message
    for (i=0; i<messageLength; i++) {
        asciiValue = (int) message[i];
        for (j=0; j<keyLength-1; j++) {
            asciiValue += (int) key[j];
        }
        encryptedMessage[i] = asciiValue;
    }
    
    printf("Encrypted message: ");
    for (i=0; i<messageLength; i++) {
        printf("%d ", encryptedMessage[i]);
        if(i == messageLength-1) {
            printf("\n");
        }
    }
    
    return 0;
}