//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Cyberpunk style encryption using XOR operation
void cyberpunk_encrypt(char* input, char* key, char* output) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    
    for (int i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

int main() {
    char message[100];
    char key[50];
    char encrypted[100];

    // Prompt user for message and key
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter your key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline character from input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypt the message using the key
    cyberpunk_encrypt(message, key, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}