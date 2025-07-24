//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This program uses a recursive encryption algorithm
    that replaces each character in the message with
    its ASCII code plus the sum of the ASCII codes of all
    the previous characters in the message.
*/

void encrypt(char *message, int total_sum) {
    int message_length = strlen(message);
    int current_sum = total_sum;
    int i;

    printf("Original message: %s\n", message);

    for (i = 0; i < message_length; i++) {
        int new_char = message[i] + current_sum;
        message[i] = new_char;
        current_sum += new_char;
    }

    printf("Encrypted message: %s\n", message);
}

int main() {
    char message[100];
    int total_sum = 0;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove trailing newline character
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, total_sum);

    return 0;
}