//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char* message, char* key) {

    srand(time(NULL));

    int messageLength = strlen(message);
    int keyLength = strlen(key);

    char encryptedMessage[messageLength + 1];

    for (int i = 0; i < messageLength; i++) {
        int randomIndex = rand() % keyLength;
        int asciiValue = (message[i] + key[randomIndex]) % 127;
        encryptedMessage[i] = (char) asciiValue;
    }
    encryptedMessage[messageLength] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

void decrypt(char* encryptedMessage, char* key) {

    int encryptedMessageLength = strlen(encryptedMessage);
    int keyLength = strlen(key);

    char decryptedMessage[encryptedMessageLength + 1];

    for (int i = 0; i < encryptedMessageLength; i++) {
        int randomIndex = i % keyLength;
        int asciiValue = (encryptedMessage[i] - key[randomIndex] + 127) % 127;
        decryptedMessage[i] = (char) asciiValue;
    }
    decryptedMessage[encryptedMessageLength] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {

    char message[100];
    char key[] = "MySecretKey";

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, key);

    char encryptedMessage[100];
    strcpy(encryptedMessage, "Kcb5Qqv@,Od3&B-6K<%4$mG>;P_4rR?Cm`%-H76#}E`P$kTQ.{Rw~y/Ak(}Xj");

    decrypt(encryptedMessage, key);

    return 0;
}