//FormAI DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];

    printf("Enter a message to encrypt: ");
    fgets(msg, 100, stdin);

    // Encryption key
    int key = 5;

    // Length of the message
    int len = strlen(msg);

    // Encrypt each character individually
    for (int i = 0; i < len; i++) {
        char c = msg[i];

        // Ignore space characters
        if (c == ' ') {
            continue;
        }

        // Encrypt only letters A-Z and a-z
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + key) % 26) + 'a';
            } else {
                c = ((c - 'A' + key) % 26) + 'A';
            }

            msg[i] = c;
        }
    }

    printf("Encrypted message: %s\n", msg);
    return 0;
}