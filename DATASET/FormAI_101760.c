//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 128

char encrypted[BUFFER_SIZE] = "";
char decrypted[BUFFER_SIZE] = "";
char key[BUFFER_SIZE] = "cryptography";
int keyLength;

void *encrypt(char *message) {
    int messageLength = strlen(message);
    int i, j;
    for (i = 0, j = 0; i < messageLength; i++, j++) {
        if (j == keyLength) {
            j = 0;
        }
        encrypted[i] = ((message[i] + key[j]) % 128);
    }
    encrypted[i] = '\0';
    printf("Encrypted text: %s\n", encrypted);
    pthread_exit(NULL);
}

void *decrypt() {
    int encryptedLength = strlen(encrypted);
    int i, j;
    for (i = 0, j = 0; i < encryptedLength; i++, j++) {
        if (j == keyLength) {
            j = 0;
        }
        decrypted[i] = ((encrypted[i] - key[j] + 128) % 128);
    }
    decrypted[i] = '\0';
    printf("Decrypted text: %s\n", decrypted);
    pthread_exit(NULL);
}

int main() {
    char message[BUFFER_SIZE];
    printf("Enter message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);

    keyLength = strlen(key);

    pthread_t threads[2];
    int create1 = pthread_create(&threads[0], NULL, encrypt, message);
    if (create1) {
        printf("Error creating encrypt thread\n");
        return 1;
    }
    int create2 = pthread_create(&threads[1], NULL, decrypt, NULL);
    if (create2) {
        printf("Error creating decrypt thread\n");
        return 1;
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}