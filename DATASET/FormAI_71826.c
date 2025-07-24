//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>

char* encrypt(char* plaintext, int key) {
    int len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);

    for(int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] + key;
    }   
    ciphertext[len] = '\0';
    return ciphertext;
}

char* decrypt(char* ciphertext, int key) {
    int len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);

    for(int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] - key;
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    char* message = "Hello World!";
    int key = 10;

    char* encrypted = encrypt(message, key);
    printf("Encrypted Message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted Message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}