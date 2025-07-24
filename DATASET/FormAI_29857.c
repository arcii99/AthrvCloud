//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    // Check for proper usage
    if (argc != 3) {
        printf("Usage: %s <key> <message>\n", argv[0]);
        return 1;
    }

    // Get the length of the key and the message
    int key_len = strlen(argv[1]);
    int msg_len = strlen(argv[2]);

    // Allocate memory for the encrypted message
    char *encrypted_msg = malloc(msg_len + 1);

    // Encrypt the message
    for (int i = 0; i < msg_len; i++) {
        encrypted_msg[i] = argv[2][i] + argv[1][i % key_len];
    }
    encrypted_msg[msg_len] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_msg);

    free(encrypted_msg);
    return 0;
}