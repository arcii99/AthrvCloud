//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program implements a simple substitution cipher, where each letter in the 
input message is replaced with a corresponding symbol to create a coded message.
The key for the encryption is a randomly generated mapping from letters to symbols.
The program allows the user to input a message, encrypt it using the generated key, 
and then decrypt the coded message back to the original message. */

int main()
{
    char plaintext[100], ciphertext[100], decryptedtext[100];
    char key[27] = {"QWERTYUIOPASDFGHJKLZXCVBNM"}; // key alphabet
    char symbols[27] = {"!@#$%^&*()_+-={}[]|;':,.<>?/"}; // symbol alphabet
    int i, j;

    // Initialize the random seed
    srand(time(NULL));

    // Generate a randomized key
    for (i = 0; i < 26; i++) {
        j = rand() % 26;
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }

    // Get input from user
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]%*c", plaintext);

    // Encrypt the message using the generated key
    for (i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] == ' ') {
            ciphertext[i] = ' ';
            continue;
        }
        for (j = 0; j < 26; j++) {
            if (key[j] == plaintext[i]) {
                ciphertext[i] = symbols[j];
                break;
            }
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("The encrypted message is: %s\n", ciphertext);

    // Decrypt the message using the generated key
    for (i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] == ' ') {
            decryptedtext[i] = ' ';
            continue;
        }
        for (j = 0; j < 26; j++) {
            if (symbols[j] == ciphertext[i]) {
                decryptedtext[i] = key[j];
                break;
            }
        }
    }
    decryptedtext[strlen(ciphertext)] = '\0';

    printf("The decrypted message is: %s\n", decryptedtext);

    return 0;
}