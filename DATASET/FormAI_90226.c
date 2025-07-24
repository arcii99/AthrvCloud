//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The key for encryption */
char *key = "turing";

/* Function to encrypt a message */
void encryption(char *message) {
    int i, j = 0, k = 0;
    char new_message[1000];

    /* Loop through each character in the message */
    for (i = 0; i < strlen(message); i++) {
        /* Rotate the key */
        if (k == strlen(key)) {
            k = 0;
        }

        /* Check if the character is a letter */
        if (message[i] >= 'a' && message[i] <= 'z') {
            /* Encrypt the letter using the key */
            new_message[j] = ((message[i] - 'a') + (key[k] - 'a')) % 26 + 'a';
            j++;
            k++;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            /* Encrypt the letter using the key */
            new_message[j] = ((message[i] - 'A') + (key[k] - 'a')) % 26 + 'A';
            j++;
            k++;
        } else {
            /* Copy the character as is */
            new_message[j] = message[i];
            j++;
        }
    }

    /* Add the null terminator to the end of the string */
    new_message[j] = '\0';

    /* Print the encrypted message */
    printf("Encrypted message: %s\n", new_message);
}

/* Main function to run the encryption */
int main() {
    char message[1000];
    printf("Enter a message to encrypt:\n");
    fgets(message, 1000, stdin);

    /* Remove the newline character from the input */
    message[strcspn(message, "\n")] = 0;

    /* Call the encryption function */
    encryption(message);

    return 0;
}