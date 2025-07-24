//FormAI DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>

/* The function takes a string message and a key as input, and returns the encrypted message. */
char* encrypt_message(char* message, char* key) {

    /* Allocate memory for the encrypted message */
    char* encrypted_message = (char*) malloc(strlen(message)+1);

    /* Loop through each character in the message */
    for(int i=0; i<strlen(message); i++) {

        /* XOR the current character in the message with the current character in the key */
        encrypted_message[i] = message[i] ^ key[i % strlen(key)];
    }

    /* Terminate the string */
    encrypted_message[strlen(message)] = '\0';
    return encrypted_message;
}

int main() {

    char message[] = "Hello, world!";
    char key[] = "secretkey";

    /* Encrypt the message */
    char* encrypted_message = encrypt_message(message, key);

    printf("Encrypted message: %s\n", encrypted_message);

    /* Free the memory allocated for the encrypted message */
    free(encrypted_message);

    return 0;
}