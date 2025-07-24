//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <string.h>

void encrypt(char *str, int key) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        str[i] = str[i] ^ (key >> (i % sizeof(int)));
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        str[i] = str[i] ^ (key >> (i % sizeof(int)));
    }
}

int main() {
    char message[] = "This is a secret message.";
    int key = 0x5F3759DF;

    printf("Original message: %s\n", message);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);
    
    return 0;
}