//FormAI DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the data using XOR key
void encrypt(char* data, char* key) {
    int data_len = strlen(data);
    int key_len = strlen(key);

    for (int i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

int main() {
    char data[] = "This is a secret message.";
    char key[] = "mykey123";

    printf("Original Data: %s\n", data);

    encrypt(data, key);

    printf("Encrypted Data: %s\n", data);

    return 0;
}