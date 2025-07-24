//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* Function prototype */
void encrypt_message(char *message, int key);

/* Recursive function to encrypt message */
void encrypt(char *ptr, int key) {
    int ascii = (int)*ptr;
    if (*ptr == '\0') return;
    else {
        /* Shift the ascii value by the key */
        ascii = ascii + key;
        /* Check if ascii value goes beyond the alphabet */
        if (ascii > 122) {
            ascii -= 26; // Subtract 26 to go back to start of alphabet
        }
        *ptr = (char)ascii;
        encrypt(ptr+1, key); // Recursive call
    }
}

/* Function to encrypt message using recursive function */
void encrypt_message(char *message, int key) {
    encrypt(message, key); // Call the recursive function
    printf("Encrypted message: %s\n", message);
}

/* Main function */
int main() {
    char *message = "hello world";
    int key = 2;
    encrypt_message(message, key);
    return 0;
}