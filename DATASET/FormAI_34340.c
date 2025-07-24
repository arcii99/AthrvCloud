//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
// Ada Lovelace-style C Encryption Example Program
// By [Your Name]

#include <stdio.h>
#include <string.h>

// Function to encrypt a string using a Caesar cipher
void encrypt(char *plaintext, int key) {
    int i;
    char ch;

    for(i = 0; plaintext[i] != '\0'; i++) {
        ch = plaintext[i];
        // Shift letter by key
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            plaintext[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            plaintext[i] = ch;
        }
    }
}

// Function to decrypt a string using a Caesar cipher
void decrypt(char *plaintext, int key) {
    int i;
    char ch;

    for(i = 0; plaintext[i] != '\0'; i++) {
        ch = plaintext[i];
        // Shift letter backwards by key
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            plaintext[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            plaintext[i] = ch;
        }
    }
}

// Main function to run the program
int main() {
    char message[100];
    int key, choice;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Choose one of the following options:\n");
    printf("1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;

        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}