//FormAI DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

int main()
{
    char message[100];
    int key;
    int choice;

    printf("Please enter the message to encrypt (max 100 characters):\n");
    scanf("%[^\n]s", message);

    printf("Please enter the key (1-25):\n");
    scanf("%d", &key);

    printf("Would you like to encrypt or decrypt the message?\n");
    printf("1. Encrypt\n2. Decrypt\n");

    scanf("%d", &choice);

    switch (choice)
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
            printf("Invalid choice.");
    }

    return 0;
}

void encrypt(char *plaintext, int key)
{
    int i;
    char ch;

    for(i = 0; plaintext[i] != '\0'; ++i){
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

    for(i = 0; ciphertext[i] != '\0'; ++i){
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