//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>

// This program encrypts a string using a simple algorithm
// It takes each character in the string and shifts it by a certain number of positions
// To decrypt the string, the same number of positions must be shifted in the opposite direction

int main() {
    char str[100], encrypted[100], decrypted[100];
    int shift;

    // Get input from user
    printf("Enter a string to be encrypted: ");
    fgets(str, 100, stdin); // allows for spaces in input

    printf("Enter the number of positions to shift: ");
    scanf("%d", &shift);

    // Encrypt the string
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            encrypted[i] = ' ';
        }
        else {
            // Shift the character by the specified amount
            encrypted[i] = (str[i] + shift) % 128;
        }
    }

    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the string
    for (int i = 0; i < strlen(encrypted); i++) {
        if (encrypted[i] == ' ') {
            decrypted[i] = ' ';
        }
        else {
            // Shift the character back to its original value
            decrypted[i] = (encrypted[i] - shift + 128) % 128;
        }
    }

    printf("Decrypted string: %s\n", decrypted);

    return 0;
}