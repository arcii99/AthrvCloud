//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char* hash(const char* data, size_t length) {
    const char* const salt = "SALTY";
    const size_t salt_length = strlen(salt);
    const size_t total_length = length + salt_length;
    unsigned char* buffer = (unsigned char*)malloc(total_length + 3);

    if (buffer == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Add salt to the beginning and end of the data
    memcpy(buffer, salt, salt_length);
    memcpy(buffer + salt_length, data, length);
    memcpy(buffer + total_length, salt, salt_length);

    // Hash the buffer using a simple XOR algorithm
    unsigned char* hash = (unsigned char*)buffer;
    for (int i = 0; i < total_length; i++) {
        hash[i % 8] ^= buffer[i];
    }

    free(buffer);
    return hash;
}

int main() {
    const char* const data = "Hello world!";
    unsigned char* hashed = hash(data, strlen(data));

    printf("Original data: %s\n", data);
    printf("Hashed data: ");
    for (int i = 0; i < 8; i++) {
        printf("%02x", hashed[i]);
    }
    printf("\n");

    free(hashed);
    return 0;
}