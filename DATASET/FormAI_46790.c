//FormAI DATASET v1.0 Category: modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* input, int key) {
    int len = strlen(input);
    char* output = (char*) malloc(sizeof(char) * (len + 1));
    memset(output, 0, len + 1);

    for(int i = 0; i < len; i++) {
        output[i] = input[i] + key;
    }

    return output;
}

char* decrypt(char* input, int key) {
    int len = strlen(input);
    char* output = (char*) malloc(sizeof(char) * (len + 1));
    memset(output, 0, len + 1);

    for(int i = 0; i < len; i++) {
        output[i] = input[i] - key;
    }

    return output;
}

int main() {
    char* message = "Hello, world!";
    int key = 10;

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}