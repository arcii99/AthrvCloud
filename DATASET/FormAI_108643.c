//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* zigzag_encrypt(char* message, int key) {
    int message_len = strlen(message);
    int num_rows = key;
    int num_cols = (message_len / (2 * key - 2) + 1) * (key - 1);
    char* encrypted_message = (char*)malloc((message_len + 1) * sizeof(char));
    int k;

    // Initialize the encrypted message
    memset(encrypted_message, 0, (message_len + 1) * sizeof(char));

    // Fill the zigzag pattern
    for (int i = 0; i < num_rows; i++) {
        k = 0;
        for (int j = i; j < message_len; j = j + 2 * (key - 1)) {
            encrypted_message[i * num_cols + k] = message[j];
            k++;
            if (i != 0 && i != key - 1 && j + 2 * (key - i - 1) < message_len) {
                encrypted_message[i * num_cols + k] = message[j + 2 * (key - i - 1)];
                k++;
            }
        }
    }

    return encrypted_message;
}

int main() {
    char message[] = "Hello World!";
    char* encrypted_message;
    int key = 3;

    encrypted_message = zigzag_encrypt(message, key);

    printf("Encrypted message: %s\n", encrypted_message);

    free(encrypted_message);

    return 0;
}