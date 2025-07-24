//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SHIFT 3   // Shift value for the Caesar Cipher

// Encryption function
void encrypt(char *plaintext, int shift) {
    int i;

    for (i = 0; i < strlen(plaintext); i++) {
        // Shift uppercase letters
        if (isupper(plaintext[i])) {
            plaintext[i] = ((plaintext[i] - 'A') + shift) % 26 + 'A';
        }
        // Shift lowercase letters
        else if (islower(plaintext[i])) {
            plaintext[i] = ((plaintext[i] - 'a') + shift) % 26 + 'a';
        }
    }
}

int main(void) {
    char plaintext[100];
    int shift;

    // Get plaintext and shift value from user
    printf("Enter plaintext: ");
    scanf("%[^\n]", plaintext);
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    // Validate shift value
    while (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please enter a value between 1 and 25: ");
        scanf("%d", &shift);
    }

    // Encrypt plaintext using Caesar Cipher
    encrypt(plaintext, shift);

    // Print encrypted text
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}