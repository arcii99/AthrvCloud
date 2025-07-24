//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare the variable to be encrypted
    char message[] = "The quick brown fox jumped over the lazy dog.";
    printf("Original message: %s\n", message);

    // Declare the encryption key
    char key[] = "elementary";
    printf("Encryption key: %s\n", key);

    // Calculate the length of the message
    int message_length = strlen(message);

    // Calculate the length of the key
    int key_length = strlen(key);

    // Declare the variables for encryption
    int i, j = 0, k;
    char encrypted[message_length];

    // Encrypt the message using the key
    for(i = 0; i < message_length; i++) {
        k = j % key_length;

        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] + key[k] - 2 * 'a') % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] + key[k] - 2 * 'A') % 26 + 'A';
        } else {
            encrypted[i] = message[i];
        }

        j++;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Declare the variables for decryption
    char decrypted[message_length];

    // Decrypt the message using the key
    for(i = 0; i < message_length; i++) {
        k = j % key_length;

        if(encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (encrypted[i] - key[k] + 26) % 26 + 'a';
        } else if(encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (encrypted[i] - key[k] + 26) % 26 + 'A';
        } else {
            decrypted[i] = encrypted[i];
        }

        j++;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}