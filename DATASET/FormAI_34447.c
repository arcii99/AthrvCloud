//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>

// Struct to hold encrypted message
typedef struct {
    char message[100];
} EncryptedMessage;

// Function to encrypt message
EncryptedMessage encryptMessage(char message[]) {
    EncryptedMessage encryptedMessage;
    
    // Loop through message and apply encryption algorithm
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage.message[i] = 'a' + (message[i] - 'a' + 3) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage.message[i] = 'A' + (message[i] - 'A' + 3) % 26;
        } else {
            encryptedMessage.message[i] = message[i];
        }
    }
    
    return encryptedMessage;
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", message);
    
    EncryptedMessage encryptedMessage = encryptMessage(message);
    printf("Encrypted message: %s\n", encryptedMessage.message);

    return 0;
}