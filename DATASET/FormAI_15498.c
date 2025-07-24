//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform Substitution Cipher
void substitutionCipher(char *text, int shift) {
    int i = 0;

    // loop through every character in the text
    while (text[i] != '\0') {
        // check if character is an uppercase letter
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A') + shift) % 26 + 'A';
        }
        // check if character is a lowercase letter
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a') + shift) % 26 + 'a';
        }

        i++;
    }
}

int main() {
    char plaintext[100], ciphertext[100];
    int shift;

    // take input from user
    printf("Enter a string to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // perform substitution cipher
    substitutionCipher(plaintext, shift);

    // print encrypted text
    printf("Encrypted text: %s", plaintext);

    // perform reverse substitution cipher
    substitutionCipher(plaintext, 26 - shift);

    // print decrypted text
    printf("Decrypted text: %s", plaintext);

    return 0;
}