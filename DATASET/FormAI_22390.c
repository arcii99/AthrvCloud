//FormAI DATASET v1.0 Category: modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "ABCDEFGHIJKLMNOP" // sample key used for encryption

// function to encrypt a string using the specified key
char* encrypt(char* input) {
    int input_length = strlen(input), key_length = strlen(KEY);
    char* output = (char*)malloc(input_length + 1);

    for(int i = 0; i < input_length; i++) {
        output[i] = input[i] ^ KEY[i % key_length]; // bitwise XOR operation with key
    }

    output[input_length] = '\0';
    return output;
}

// function to decrypt an encrypted string using the specified key
char* decrypt(char* input) {
    int input_length = strlen(input), key_length = strlen(KEY);
    char* output = (char*)malloc(input_length + 1);

    for(int i = 0; i < input_length; i++) {
        output[i] = input[i] ^ KEY[i % key_length]; // bitwise XOR operation with key
    }

    output[input_length] = '\0';
    return output;
}

int main() {
    char input[100], *encrypted_message, *decrypted_message;

    printf("Enter message to encrypt: ");
    scanf("%s", input);

    encrypted_message = encrypt(input);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}