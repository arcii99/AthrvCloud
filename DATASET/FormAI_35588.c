//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *msg, int key) {
    int len = strlen(msg);
    for (int i = 0; i < len; i++) {
        msg[i] = (msg[i] + key) % 128;
    }
}

void decrypt(char *msg, int key) {
    int len = strlen(msg);
    for (int i = 0; i < len; i++) {
        msg[i] = (msg[i] - key + 128) % 128;
    }
}

int main() {
    printf("Greetings! This program demonstrates a modern encryption technique.\n");

    char message[100];
    int key;

    printf("Please enter a message to encrypt:\n");
    fgets(message, 100, stdin);
    printf("Please enter a key for encryption:\n");
    scanf("%d", &key);

    encrypt(message, key);
    printf("The encrypted message is: %s\n", message);

    decrypt(message, key);
    printf("The decrypted message is: %s\n", message);

    printf("Thank you for using this program!\n");
    return 0;
}