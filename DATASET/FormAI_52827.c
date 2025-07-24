//FormAI DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main() {
    char msg[MAX_LEN];
    char key[MAX_LEN];

    printf("Enter message to encrypt: ");
    scanf("%[^\n]", msg);
    getchar(); // clear input buffer

    printf("Enter encryption key: ");
    scanf("%[^\n]", key);
    getchar(); // clear input buffer

    int msg_len = strlen(msg);
    int key_len = strlen(key);

    char encrypted_msg[MAX_LEN] = ""; // initialize to empty string

    // perform encryption
    for (int i = 0; i < msg_len; i++) {
        int j = i % key_len;
        char c = ((msg[i] - 'A') + (key[j] - 'A')) % 26 + 'A';
        strncat(encrypted_msg, &c, 1);
    }

    printf("Encrypted message: %s\n", encrypted_msg);

    return 0;
}