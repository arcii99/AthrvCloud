//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define KEY 5

void encrypt(char message[])
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch += KEY;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch += KEY;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char message[])
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch -= KEY;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch -= KEY;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}

int main()
{
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    encrypt(message);
    printf("Encrypted message: %s\n", message);

    decrypt(message);
    printf("Decrypted message: %s", message);

    return 0;
}