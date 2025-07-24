//FormAI DATASET v1.0 Category: modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform the encryption of the input string using the key
char* encrypt(char* input, char* key) {
    int len1 = strlen(input), len2 = strlen(key);
    char* result = (char*) malloc((len1+1) * sizeof(char));
    result[len1] = '\0';
    for (int i = 0; i < len1; i++) {
        result[i] = (input[i] + key[i%len2]) % 256;
    }
    return result;
}

int main() {
    char* message = "This is a secret message.";
    char* key = "encryption";
    char* encrypted_msg = encrypt(message, key);
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_msg);
    free(encrypted_msg);
    return 0;
}