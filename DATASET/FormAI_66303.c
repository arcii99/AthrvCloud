//FormAI DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

int main()
{
    char message[MAX_STRING_LENGTH];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline

    printf("Enter key (integer between 1 and 25): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *plaintext, int key)
{
    int i;
    char ch;

    for(i = 0; plaintext[i] != '\0'; i++){
        ch = plaintext[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            plaintext[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            plaintext[i] = ch;
        }
    }
}

void decrypt(char *ciphertext, int key)
{
    int i;
    char ch;

    for(i = 0; ciphertext[i] != '\0'; i++){
        ch = ciphertext[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            ciphertext[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            ciphertext[i] = ch;
        }
    }
}