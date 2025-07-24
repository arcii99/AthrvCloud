//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char message[100], ciphertext[100];
    int i, j, key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("Invalid key, program will exit.\n");
        return 1;
    }

    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            ciphertext[i] = ((message[i] - 'a') + key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            ciphertext[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } else {
            ciphertext[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}