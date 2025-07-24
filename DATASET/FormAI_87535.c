//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *key) {
    int input_length = strlen(input);
    int key_length = strlen(key);
    int key_index = 0;
    for (int i = 0; i < input_length; i++) {
        input[i] ^= key[key_index];
        key_index++;
        if (key_index >= key_length) {
            key_index = 0;
        }
    }
}

void decrypt(char *input, char *key) {
    // Decryption is same as encryption because XOR is a reversible operation
    encrypt(input, key);
}

int main() {
    char input[1000];
    char key[100];

    printf("Enter the string to encrypt: ");
    fgets(input, sizeof(input), stdin);

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline character from input and key
    input[strcspn(input, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the string
    encrypt(input, key);
    printf("Encrypted string: %s\n", input);

    // Decrypt the string
    decrypt(input, key);
    printf("Decrypted string: %s\n", input);

    return 0;
}