//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key);

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);

    printf("Encrypted message: %s\n", encrypted);

    free(encrypted);
}

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* result = (char*)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a') + key) % 26 + 'a';
        } else {
            result[i] = message[i];
        }
    }

    return result;
}