//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encrypt(char message[], int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
        else if (message[i] >= '0' && message[i] <= '9') {
            message[i] = ((message[i] - '0') + key) % 10 + '0';
        }
    }
}

int main() {
    printf("Enter the message to encrypt: ");
    char message[100];
    fgets(message, 100, stdin);

    printf("Enter the encryption key: ");
    int key;
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    return 0;
}