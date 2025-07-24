//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to \"Unique Encryption Program\"! Let's get started...\n");

    char message[100];
    int key;

    // Get the message to encrypt from the user
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Get the encryption key from the user
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    // Encrypt the message using the encryption key
    int i = 0;
    char encrypted[100];
    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (char) (((message[i] - 'a') + key) % 26 + 'a');
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (char) (((message[i] - 'A') + key) % 26 + 'A');
        } else {
            encrypted[i] = message[i];
        }
        i++;
    }
    encrypted[i] = '\0';

    printf("\nEncrypted message: %s\n", encrypted);

    printf("\nThank you for using our program!\n");

    return 0;
}