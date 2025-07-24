//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Caesar Cipher Encryption
char* caesar_cipher(char* message, int key) {
    int length = strlen(message);
    char* cipher_text = (char*)malloc(length * sizeof(char));
    for(int i=0; i < length; i++) {
        cipher_text[i] = message[i] + key;
    }
    return cipher_text;
}

// Vigenere Cipher Encryption
char* vigenere_cipher(char* message, char* key) {
    int length = strlen(message);
    int key_length = strlen(key);
    char* cipher_text = (char*)malloc(length * sizeof(char));
    for(int i=0; i < length; i++) {
        cipher_text[i] = ((message[i] + key[i%key_length]) % 26) + 'A';
    }
    return cipher_text;
}

int main() {
    char message[] = "HELLO WORLD";
    char* cipher_text_caesar = caesar_cipher(message, 3);
    char* cipher_text_vigenere = vigenere_cipher(message, "KEY");
    
    printf("Caesar Cipher: %s\n", cipher_text_caesar);
    printf("Vigenere Cipher: %s\n", cipher_text_vigenere);
    
    free(cipher_text_caesar);
    free(cipher_text_vigenere);
    return 0;
}