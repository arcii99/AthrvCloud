//FormAI DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define KEY 42

void encryption(char* plaintext, char* ciphertext, int key) {
    int i;
    for (i = 0; i < MAX_BUFFER_SIZE && plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] + key;
    }
    ciphertext[i] = '\0';
}

void decryption(char* ciphertext, char* plaintext, int key) {
    int i;
    for (i = 0; i < MAX_BUFFER_SIZE && ciphertext[i] != '\0'; i++) {
        plaintext[i] = ciphertext[i] - key;
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[MAX_BUFFER_SIZE];
    char ciphertext[MAX_BUFFER_SIZE];
    char decrypted_plaintext[MAX_BUFFER_SIZE];
    
    printf("Enter your plaintext:");
    fgets(plaintext, MAX_BUFFER_SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; //remove newline character
    
    // Encrypt plaintext
    encryption(plaintext, ciphertext, KEY);
    
    // Print the encrypted ciphertext
    printf("\nEncrypted ciphertext: ");
    for (int i = 0; i < strlen(ciphertext); i++) {
        printf("%02X", (unsigned char)(ciphertext[i]));
    }
    
    // Decrypt the ciphertext
    decryption(ciphertext, decrypted_plaintext, KEY);
    
    // Print the decrypted plaintext
    printf("\nDecrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}