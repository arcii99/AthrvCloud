//FormAI DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define the plaintext and key
    char plaintext[1000];
    char key[1000];

    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key for encryption: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline character from the strings
    plaintext[strcspn(plaintext, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    const int plaintextLength = strlen(plaintext);
    const int keyLength = strlen(key);
    int i;

    // Generate the ciphertext
    char ciphertext[1000];
    for (i = 0; i < plaintextLength; i++){
        char c = plaintext[i] ^ key[i % keyLength];
        sprintf(&ciphertext[i], "%02X", c);
    }
    
    // Print the encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char decryptedPlaintext[1000];
    for (i=0; i<plaintextLength; i+=2){
        char c[3] = {ciphertext[i], ciphertext[i + 1], '\0'};
        char x = (char) strtol(c, NULL, 16);
        char d = x ^ key[i % keyLength];
        sprintf(&decryptedPlaintext[i], "%c", d);
    }

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decryptedPlaintext);

    return 0;
}