//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryption(char* message, int key) {
    int messageLength = strlen(message);
    // Allocate memory for encrypted message
    char* encryptedMessage = (char*)malloc(messageLength * sizeof(char));
    // Encrypt the message using Caesar cipher
    for (int i = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encryptedMessage[i] = ((message[i] - 'A') + key) % 26 + 'A';
            }
            else {
                encryptedMessage[i] = ((message[i] - 'a') + key) % 26 + 'a';
            }
        }
        else {
            encryptedMessage[i] = message[i];
        }
    }
    printf("Encrypted Message: %s\n", encryptedMessage);
    free(encryptedMessage);
}

int main() {
    char message[100];
    int key;
    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);
    printf("Enter key: ");
    scanf("%d", &key);
    encryption(message, key);
    return 0;
}