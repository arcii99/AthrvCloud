//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Surprise! This program generates a form of modern encryption
    printf("Welcome to the modern encryption program!\n\n");
    printf("Please enter a message to be encrypted: ");

    // Store the message entered by the user
    char message[100];
    fgets(message, 100, stdin);

    // Generate the encryption by shuffling the letters in the message
    for (int i = 0; message[i] != '\0'; i++) {
        // Randomly select a position to swap with
        int j = rand() % (i + 1);
        // Swap the characters at position i and j
        char temp = message[i];
        message[i] = message[j];
        message[j] = temp;
    }

    // Output the encrypted message
    printf("\nYour encrypted message is: %s\n", message);

    return 0;
}