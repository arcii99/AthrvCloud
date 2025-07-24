//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// An enthusiastic C Encryption program!

int main() {
    // Greetings and user prompts
    printf("Welcome to this amazing C Encryption program!\n");
    printf("Please enter the message you want to encrypt:\n");
    char message[1000];
    scanf("%[^\n]", message);
    getchar(); // flush out the newline character
    
    // Generating encryption key
    srand(time(NULL));
    char encryptionKey[26];
    for (int i = 0; i < 26; i++) {
        encryptionKey[i] = rand() % 26 + 'A'; // ASCII value for capital letters
    }
    
    // Encrypting the message
    int messageLen = strlen(message);
    char encryptedMessage[messageLen + 1]; // +1 for null terminator
    strcpy(encryptedMessage, message); // copying the message to the encrypted message variable
    for (int i = 0; i < messageLen; i++) {
        if (encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z') { // only encrypt capital letters
            encryptedMessage[i] = encryptionKey[encryptedMessage[i] - 'A']; // shift by the ASCII value of 'A'
        }
    }
    
    // Outputting the results
    printf("Your encrypted message is: %s\n", encryptedMessage);
    printf("Your encryption key is: %s\n", encryptionKey);
    printf("Keep your key safe and secure! Happy encrypting!");

    return 0;
}