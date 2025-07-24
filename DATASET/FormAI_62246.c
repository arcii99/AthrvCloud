//FormAI DATASET v1.0 Category: modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt plain text
void encrypt(char *plaintext, int key){
    int i;
    char ch;

    for(i = 0; plaintext[i] != '\0'; ++i){
        ch = plaintext[i];

        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            plaintext[i] = ch;
        }

        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            plaintext[i] = ch;
        }
    }
}

// Function to decrypt the encrypted text
void decrypt(char *ciphertext, int key){
    int i;
    char ch;

    for(i = 0; ciphertext[i] != '\0'; ++i){
        ch = ciphertext[i];

        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            ciphertext[i] = ch;
        }

        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            ciphertext[i] = ch;
        }
    }
}

// Main function
int main(){
    char message[1000];
    int key, choice;

    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}