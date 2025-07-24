//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void) {
    char plaintext[MAX_LENGTH], ciphertext[MAX_LENGTH];
    char key[] = "secretkey";

    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);

    // Remove newline character from plaintext
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Encryption
    int i, j;
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);
    for(i = 0, j = 0; i < plaintext_len; ++i, j = (j + 1) % key_len) {
        ciphertext[i] = (plaintext[i] ^ key[j]) + key[j];      
    }
    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    // Decryption
    char decrypted[MAX_LENGTH];
    for(i = 0, j = 0; i < plaintext_len; ++i, j = (j + 1) % key_len) {
        decrypted[i] = (ciphertext[i] - key[j]) ^ key[j];
    }
    decrypted[i] = '\0';

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}