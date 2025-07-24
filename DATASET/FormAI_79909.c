//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char message[100];
    printf("Please enter your message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;

    char key[100];
    printf("Please enter your key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0;

    int message_len = strlen(message);
    int key_len = strlen(key);

    char encrypted_message[100];
    for (int i = 0; i < message_len; i++) {
        // In this surreal implementation, we will split chars into digits
        int message_digit = message[i] % 10;
        int key_digit = key[i % key_len] % 10;

        // We will add the digits together and then subtract the length of the key
        // from the result, ensuring that it is a printable ASCII character
        int encrypted_digit = (message_digit + key_digit - key_len) % 10 + 32;

        encrypted_message[i] = encrypted_digit;
    }

    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}