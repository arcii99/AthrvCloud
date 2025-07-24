//FormAI DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>

void encrypt(char* text, char* key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    int i;
    for(i=0;i<text_length;i++){
        text[i] ^= key[i%key_length];
    }
}

void decrypt(char* cipher, char* key) {
    int cipher_length = strlen(cipher);
    int key_length = strlen(key);
    int i;
    for(i=0;i<cipher_length;i++){
        cipher[i] ^= key[i%key_length];
    }
}

int main() {
    char text[] = "This is a secret message.";
    char key[] = "encryption";
    printf("Original message: %s\n", text);

    encrypt(text, key);
    printf("Encrypted message: %s\n", text);

    decrypt(text, key);
    printf("Decrypted message: %s\n", text);
    return 0;
}