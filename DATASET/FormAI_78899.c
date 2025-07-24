//FormAI DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key);

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char *message, int key) {
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] + key - 'a') % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] + key - 'A') % 26) + 'A';
        }
    }
}