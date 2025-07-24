//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Medieval encryption key
    char key[] = "Excalibur";

    printf("Enter the message:");
    char message[1000];
    fgets(message, 1000, stdin);
    
    // Remove the newline character at the end of the message string
    message[strcspn(message, "\n")] = '\0';

    // Calculate length of message and key
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Generate key stream based on the length of the message
    char keystream[message_length];

    // Use the key to generate the keystream
    int i, j;
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length)
            j = 0;
        keystream[i] = key[j];
    }

    // Encrypt the message using the keystream
    char encrypted_message[message_length];
    for (i = 0; i < message_length; i++) {
        encrypted_message[i] = ((message[i] - 'a' + keystream[i] - 'a') % 26) + 'a';
    }

    // Print the encrypted message
    printf("The encrypted message is: %s\n", encrypted_message);

    // Decrypt the message using the keystream
    char decrypted_message[message_length];
    for (i = 0; i < message_length; i++) {
        decrypted_message[i] = ((encrypted_message[i] - keystream[i] + 26) % 26) + 'a';
    }

    // Print the decrypted message
    printf("The decrypted message is: %s\n", decrypted_message);

    return 0;
}