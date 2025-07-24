//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key) {
    int i;
    for(i=0; i<strlen(message); i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char* message, int key) {
    int i;
    for(i=0; i<strlen(message); i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    char message[100];
    int key;

    printf("Hello there, I am the amazing Encrypt-o-tron!\n");
    printf("Please enter a message to encrypt: ");
    scanf("%s", message);
    printf("Please enter a key to encrypt with: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Your encrypted message is: %s\n", message);

    printf("\nNow it's time to decrypt!\n");
    printf("Please enter the key to decrypt with: ");
    scanf("%d", &key);

    decrypt(message, key);
    printf("Your decrypted message is: %s\n", message);

    return 0;
}