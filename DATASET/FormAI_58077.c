//FormAI DATASET v1.0 Category: modern Encryption ; Style: mathematical
#include <stdio.h>

int main() {
    // Encryption key and message to encrypt
    int key = 5;
    char message[50] = "HELLO WORLD";

    // Encryption process
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + ((message[i] - 'A' + key) % 26);
        }
    }

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}