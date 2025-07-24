//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    int i;
    int plaintext_len;
    int key_len;

    // Get input from user
    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);
    plaintext_len = strlen(plaintext) - 1; // Subtract 1 to remove newline character
    printf("Enter key: ");
    fgets(key, 100, stdin);
    key_len = strlen(key) - 1;

    // Check if key is shorter than plaintext, if it is, repeat the key
    if (key_len < plaintext_len) {
        int repeat_times = plaintext_len / key_len;
        int remainder = plaintext_len % key_len;
        char repeated_key[100];
        for (i = 0; i < repeat_times; i++) {
            strncat(repeated_key, key, key_len);
        }
        strncat(repeated_key, key, remainder);
        strncpy(key, repeated_key, plaintext_len);
    }

    // Encrypt plaintext with key using XOR bitwise operation
    for (i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }

    // Print ciphertext
    printf("Ciphertext: ");
    for (i = 0; i < plaintext_len; i++) {
        printf("%x", ciphertext[i]);
    }

    printf("\n");

    return 0;
}