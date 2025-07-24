//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        message[i] += key;
    }
}

void decrypt(char message[], int key) {
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        message[i] -= key;
    }
}

int main() {
    char message[100];
    int key;

    // Read message and encryption key from user
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt message and print result
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    // Decrypt message and print result
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}