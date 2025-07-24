//FormAI DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Encryption function
void encrypt(char* message, int key)
{
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        // Encrypting uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
        // Encrypting lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        // Ignoring special characters
        else{
            continue;
        }
    }
}

//Decryption function
void decrypt(char* message, int key)
{
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        // Decrypting uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
        // Decrypting lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        // Ignoring special characters
        else{
            continue;
        }
    }
}

// Main function
int main()
{
    char message[1000];
    int key, choice;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("\n1. Encrypt message\n2. Decrypt message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}