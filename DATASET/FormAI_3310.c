//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[1000];
    char encryptedMessage[1000];
    char key[100];
    int keyIndex = 0;

    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    // loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // ignore spaces and newlines
        if (message[i] != ' ' && message[i] != '\n') {
            // get the corresponding character in the key
            char keyChar = key[keyIndex % strlen(key)];

            // perform the encryption calculation
            char encryptedChar = ((message[i] - 97) + (keyChar - 97)) % 26 + 97;

            // add the encrypted character to the final message
            encryptedMessage[i] = encryptedChar;

            // increment the key index to move to the next character
            keyIndex++;
        } else {
            // add spaces and newlines to the final message
            encryptedMessage[i] = message[i];
        }
    }

    printf("Encrypted message: %s", encryptedMessage);

    return 0;
}