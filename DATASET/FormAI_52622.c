//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    //Declare variables
    char message[1000];
    char key[100];
    int messageLength, keyLength, i, j;
    
    //Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    messageLength = strlen(message) - 1;
    
    //Get encryption key from user
    printf("Enter encryption key: ");
    fgets(key, 100, stdin);
    keyLength = strlen(key) - 1;
    
    //Add padding to key if necessary
    if (keyLength < messageLength) {
        int difference = messageLength - keyLength;
        for (i = 1; i <= difference; i++) {
            key[keyLength] = key[keyLength - i];
        }
        for (i = 0; i < difference; i++) {
            key[i] = key[keyLength - difference - i];
        }
        keyLength = messageLength;
    }
    
    //Encrypt message
    for (i = 0; i < messageLength; i++) {
        message[i] = (message[i] + key[i]) % 128;
    }
    
    //Print encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < messageLength; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
    
    return 0;
}