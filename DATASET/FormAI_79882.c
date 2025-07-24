//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3

char* encrypt(char* plaintext) {
    int length = strlen(plaintext);
    char* ciphertext = (char*) malloc((length + 1) * sizeof(char)); // allocate memory

    for(int i = 0; i < length; i++) {
        char currentChar = plaintext[i];
        if(currentChar >= 'a' && currentChar <= 'z') { // shift lowercase letters
            currentChar = ((currentChar - 'a') + SHIFT) % 26 + 'a';
        } else if (currentChar >= 'A' && currentChar <= 'Z') { // shift uppercase letters
            currentChar = ((currentChar - 'A') + SHIFT) % 26 + 'A';
        }
        ciphertext[i] = currentChar;
    }
    ciphertext[length] = '\0'; // terminate string with null character

    return ciphertext;
}

int main() {
    char plaintext[100];
    char* ciphertext;

    printf("Enter a plaintext message: ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove newline character

    ciphertext = encrypt(plaintext);
    printf("Encrypted message: %s\n", ciphertext);

    free(ciphertext); // deallocate memory

    return 0;
}