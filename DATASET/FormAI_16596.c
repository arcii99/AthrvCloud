//FormAI DATASET v1.0 Category: Encryption ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        encrypted[i] = message[i] + key;
    }

    return encrypted;
}

char* decrypt(char* encrypted, int key) {
    int length = strlen(encrypted);
    char* decrypted = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        decrypted[i] = encrypted[i] - key;
    }

    return decrypted;
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("\nEncrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("\nDecrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}