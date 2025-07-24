//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key);

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char* message, int key) {
    if(*message == '\0') {
        return;
    }
    if(*message >= 'a' && *message <= 'z') {
        *message = ((*message - 'a' + key) % 26) + 'a';
    }
    else if(*message >= 'A' && *message <= 'Z') {
        *message = ((*message - 'A' + key) % 26) + 'A';
    }
    encrypt(message + 1, key);
}