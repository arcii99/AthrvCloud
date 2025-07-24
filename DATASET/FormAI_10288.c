//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] += key;  // add the key to each character in the message
    }
}

void decrypt(char *message, int key) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] -= key;  // subtract the key from each character in the message
    }
}

int main() {
    char message[100];
    int key;

    // get message from user
    printf("Enter message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;  // remove the newline character

    // get encryption key from user
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}