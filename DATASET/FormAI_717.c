//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xor_encrypt(char* input, int input_len, char* key, int key_len) {
    int i, j;
    for (i = 0, j = 0; i < input_len; i++, j++) {
        if (j == key_len) j = 0; // Repeating key if it is shorter than message
        input[i] ^= key[j]; // xor each character with its corresponding key character
    }
}

void xor_decrypt(char* input, int input_len, char* key, int key_len) {
    int i, j;
    for (i = 0, j = 0; i < input_len; i++, j++) {
        if (j == key_len) j = 0; // Repeating key if it is shorter than message
        input[i] ^= key[j]; // xor each character with its corresponding key character
    }
}

int main() {
    char message[] = "This is a secret message"; // Message to encrypt
    char key[] = "secret_key"; // Encryption key
    int message_len = strlen(message);
    int key_len = strlen(key);
    char encrypted_message[message_len]; // Array to hold encrypted message
    char decrypted_message[message_len]; // Array to hold decrypted message
    
    strcpy(encrypted_message, message);
    xor_encrypt(encrypted_message, message_len, key, key_len); // Encrypt the message using the key
    printf("Encrypted Message: %s\n", encrypted_message); // Display encrypted message
    strcpy(decrypted_message, encrypted_message);
    xor_decrypt(decrypted_message, message_len, key, key_len); // Decrypt the message using the key
    printf("Decrypted Message: %s\n", decrypted_message); // Display decrypted message
    
    return 0;
}