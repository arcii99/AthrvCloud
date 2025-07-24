//FormAI DATASET v1.0 Category: modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main()
{
    // Get user input
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    int key;
    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

// Function to encrypt the message
void encrypt(char* message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
    }
}