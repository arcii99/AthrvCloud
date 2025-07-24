//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include<stdio.h>

/* 
 * This program demonstrates a basic encryption algorithm where
 * each character of a string is replaced by a new character with a fixed offset.
 * The offset is a key that needs to be kept secret in order to decrypt the message.
 */

#define KEY 4

void encrypt(char *string) {
    for(; *string; ++string) {
        *string = (*string + KEY) % 127;
    }
}

void decrypt(char *string) {
    for(; *string; ++string) {
        *string = (*string - KEY + 127) % 127;
    }
}

int main() {
    char message[1024], option;
    printf("Enter a message: ");
    fgets(message, 1024, stdin);
    printf("Would you like to encrypt or decrypt the message? (e/d): ");
    scanf(" %c", &option);
    if(option == 'e') {
        encrypt(message);
        printf("Encrypted message: %s", message);
    }
    else if(option == 'd') {
        decrypt(message);
        printf("Decrypted message: %s", message);
    }
    else {
        printf("Invalid option.");
    }
    return 0;
}