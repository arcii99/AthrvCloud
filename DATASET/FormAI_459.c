//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main()
{
    char message[MAX_LENGTH];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // remove newline character from message
    message[strlen(message)-1] = '\0';

    printf("\nOriginal message: %s\n\n", message);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}