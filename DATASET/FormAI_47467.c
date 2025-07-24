//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
/* Romeo and Juliet Encryption */
/* By: [Your Name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];

    printf("Oh Romeo, my dear Romeo, what message have you for me tonight?\n");
    fgets(message, MAX_LENGTH, stdin);

    printf("My sweet Juliet, I have a key that will keep our secrets safe. What word shall we choose?\n");
    fgets(key, MAX_LENGTH, stdin);

    // Remove newline character from key
    key[strcspn(key, "\n")] = 0;

    int message_length = strlen(message);
    int key_length = strlen(key);

    // Pad the key to be the same length as the message
    if (key_length < message_length) {
        int difference = message_length - key_length;
        for (int i = 0; i < difference; i++) {
            key[key_length + i] = key[i];
        }
        key[message_length] = '\0';
    }

    // Encrypt the message using the key
    for (int i = 0; i < message_length; i++) {
        char encrypted_char = (message[i] + key[i]) % 126;
        printf("%c", encrypted_char);
    }

    return 0;
}