//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program will take a message from the user
 * and encrypt it using a unique encryption method developed by the author.
 */

char* encrypt(char* message);

int main() {

    printf("Enter your message: ");

    char message[100];
    scanf("%[^\n]", message);

    char* encrypted_message = encrypt(message);

    printf("Encrypted message: %s", encrypted_message);

    free(encrypted_message);
    return 0;
}

char* encrypt(char* message) {
    srand(42); // Setting constant seed for repeatability

    int length = strlen(message);
    char* encrypted_message = malloc(length + 1);

    int i;
    for (i = 0; i < length; i++) {
        char encrypted_char = message[i] + (rand() % 100);
        if (encrypted_char > 126) {
            encrypted_char = encrypted_char - 95;
        }

        encrypted_message[i] = encrypted_char;
    }

    encrypted_message[length] = '\0';

    return encrypted_message;
}