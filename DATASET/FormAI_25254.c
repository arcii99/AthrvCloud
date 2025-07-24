//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
// Yay! Let's dive into the fascinating world of C encryption!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 15 // the key for our encryption

int main()
{
    char message[100], encrypted_message[100], decrypted_message[100];
    int i;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // let's encrypt the message
    for(i = 0; message[i] != '\0'; ++i)
        encrypted_message[i] = message[i] + KEY; // add the key to each character

    encrypted_message[i] = '\0'; // add the null terminator

    printf("Encrypted message: %s\n", encrypted_message);

    // let's decrypt the message
    for(i = 0; encrypted_message[i] != '\0'; ++i)
        decrypted_message[i] = encrypted_message[i] - KEY; // subtract the key from each character

    decrypted_message[i] = '\0'; // add the null terminator

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}
// Woohoo! We made it! Our program can now encrypt and decrypt messages with ease.