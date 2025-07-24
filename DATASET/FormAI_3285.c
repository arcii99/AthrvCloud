//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000

// function to perform digital watermarking on message using secret key
void perform_watermarking(char *msg, char *key) {
    int i, len_msg = strlen(msg), len_key = strlen(key);
    for(i = 0; i < len_msg; i++) {
        // bitwise XOR operation between message and secret key
        msg[i] ^= key[i % len_key];
    }
}

int main() {
    char message[MAX_MSG_LENGTH], key[MAX_MSG_LENGTH];
    printf("Enter the message to be watermarked: ");
    fgets(message, MAX_MSG_LENGTH, stdin);
    printf("Enter the secret key: ");
    fgets(key, MAX_MSG_LENGTH, stdin);
    // remove newline character from input strings
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    // perform digital watermarking on message
    perform_watermarking(message, key);
    printf("Watermarked message: %s\n", message);
    return 0;
}