//FormAI DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100

// Function to encrypt the message using Caesar cypher
void encrypt(char *msg, int key) {
    int len = strlen(msg);
    for (int i = 0; i < len; ++i) {
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = ((msg[i] - 'A' + key) % 26) + 'A';
        } else if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = ((msg[i] - 'a' + key) % 26) + 'a';
        }
    }
}

int main() {
    char message[MAX_MSG_LEN];
    int key;

    // Get message and key from user
    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';  // remove newline character
    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}