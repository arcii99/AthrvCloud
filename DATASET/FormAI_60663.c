//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>

#define KEY '&'


int main() {
    
    char message[100];
    int i, length;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message); // Reading a sentence with spaces

    length = strlen(message); // Getting length of the sentence

    // Loop through each character of the message
    for(i = 0; i < length; i++) {
        message[i] = message[i] ^ KEY; // Encrypting the message by XOR-ing it with the key
    }

    printf("Encrypted message: %s\n", message);

    // Decrypting the message by XOR-ing it with the key again
    for(i = 0; i < length; i++) {
        message[i] = message[i] ^ KEY;
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}