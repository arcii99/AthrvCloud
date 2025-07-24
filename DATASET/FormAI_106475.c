//FormAI DATASET v1.0 Category: modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char message[BUFFER_SIZE];
    int key;
} EncryptedMessage;

void encryptMessage(char* message, int key) {
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] + key;  
    }
}

void* encryptionThread(void* args) {
    EncryptedMessage* encryptedMessage = (EncryptedMessage*) args;
    encryptMessage(encryptedMessage->message, encryptedMessage->key);
    pthread_exit(NULL);
}

int main() {
    char message[BUFFER_SIZE];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    EncryptedMessage encryptedMessage;
    strcpy(encryptedMessage.message, message);
    encryptedMessage.key = key;

    pthread_t encryption_thread;
    pthread_create(&encryption_thread, NULL, encryptionThread, (void*) &encryptedMessage);
    pthread_join(encryption_thread, NULL);

    printf("Encrypted message: %s", encryptedMessage.message);

    return 0;
}