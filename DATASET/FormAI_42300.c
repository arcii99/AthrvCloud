//FormAI DATASET v1.0 Category: modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN], key[MAX_LEN], encrypted[MAX_LEN];
    int input_len, key_len, i;

    // Get input string from user
    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    input_len = strlen(input);

    // Get encryption key from user
    printf("Enter an encryption key: ");
    fgets(key, MAX_LEN, stdin);
    key_len = strlen(key);

    // Remove newlines from user input and key
    input[strcspn(input, "\r\n")] = 0;
    key[strcspn(key, "\r\n")] = 0;

    // Pad encryption key with itself until it is at least as long as input
    while (strlen(key) < input_len) {
        strcat(key, key);
    }

    // Perform encryption by XORing input string with padded encryption key
    for (i = 0; i < input_len; i++) {
        encrypted[i] = input[i] ^ key[i];
    }

    // Print encrypted string
    printf("Encrypted string: %s\n", encrypted);

    return 0;
}