//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 100

// Function to encrypt the message
void encrypt(char *msg, int key)
{
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
}

// Function to decrypt the message
void decrypt(char *msg, int key)
{
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key; 
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
}

int main()
{
    char str[MAX_LIMIT];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(str, MAX_LIMIT, stdin);

    printf("Enter key to encrypt: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(str, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", str);

    // Decrypt the message
    decrypt(str, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", str);

    return 0;
}