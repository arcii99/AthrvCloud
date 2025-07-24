//FormAI DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Define the key to be used for encryption
char key[] = "The moon was a ghostly galleon";

// Define the surrealist message to be encrypted
char message[] = "The surrealists were playing a game of exquisite corpse";

int main() {
    int key_length = strlen(key);
    int message_length = strlen(message);

    // Allocate memory for the encrypted message
    char* encrypted_message = (char*) malloc(message_length + 1);

    // Loop through each character in the message
    for (int i = 0; i < message_length; i++) {
        // Get the ASCII value of the current character in the message
        int message_ascii = (int) message[i];

        // Subtract the ASCII value of the current character in the key
        int key_ascii = (int) key[i % key_length];
        int difference = message_ascii - key_ascii;

        // Ensure the difference is between 0 and 255
        while (difference < 0) {
            difference += 256;
        }
        while (difference > 255) {
            difference -= 256;
        }

        // Convert the difference back to a character
        char encrypted_char = (char) difference;

        // Add the encrypted character to the encrypted message
        encrypted_message[i] = encrypted_char;
    }

    // Add the terminating character to the encrypted message
    encrypted_message[message_length] = '\0';

    // Print the encrypted message
    printf("The surrealists were chased by a pack of wild dogs that were actually clocks: %s\n", encrypted_message);

    return 0;
}