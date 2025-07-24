//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

char* encrypt(char* message, int key) {
    char* encrypted = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int i;
    for (i=0; i<strlen(message); i++) {
        encrypted[i] = message[i] + key;
    }
    encrypted[i] = '\0';
    return encrypted;
}

char* decrypt(char* message, int key) {
    char* decrypted = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int i;
    for (i=0; i<strlen(message); i++) {
        decrypted[i] = message[i] - key;
    }
    decrypted[i] = '\0';
    return decrypted;
}

int main() {

    char* message = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    getchar();

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    free(decrypted);

    free(message);
    return 0;
}