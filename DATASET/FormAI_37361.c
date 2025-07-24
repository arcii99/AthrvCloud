//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <string.h>

void encrypt(char* message) {
    int len = strlen(message);

    // loop through each character in the message
    for(int i=0; i<len; i++) {
        // add 3 to ASCII value of each character
        message[i] = message[i] + 3;
    }
}

void decrypt(char* message) {
    int len = strlen(message);

    // loop through each character in the message
    for(int i=0; i<len; i++) {
        // subtract 3 from ASCII value of each character
        message[i] = message[i] - 3;
    }
}

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // remove newline character at the end of the message
    message[strcspn(message, "\n")] = '\0';

    // encrypt message
    encrypt(message);

    printf("Encrypted message: %s\n", message);

    // decrypt message
    decrypt(message);

    printf("Decrypted message: %s\n", message);

    return 0;
}