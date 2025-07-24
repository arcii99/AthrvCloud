//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
/*
 * Ada Lovelace Style Encryption Program in C
 *
 * This program takes in a string input and encrypts it using a unique algorithm designed by Ada Lovelace.
 * It then outputs the encrypted string. The decryption algorithm is left as an exercise for the reader.
 *
 * Author: Ada Lovelace
 * Date: September 1842
 */

#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str, int length) {
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char inputString[256];
    int encryptionKey = 42;

    // Take input from user
    printf("Enter string to encrypt: ");
    fgets(inputString, 256, stdin);

    // Remove newline character from input
    inputString[strcspn(inputString, "\n")] = 0;

    // Calculate length of input string
    int length = strlen(inputString);

    // Reverse input string and output
    reverseString(inputString, length);
    printf("Reversed string: %s\n", inputString);

    // XOR each character with encryption key
    for(int i = 0; i < length; i++) {
        inputString[i] = inputString[i] ^ encryptionKey;
    }

    // Output encrypted string
    printf("Encrypted string: %s\n", inputString);

    return 0;
}