//FormAI DATASET v1.0 Category: Encryption ; Style: medieval
#include<stdio.h>
#include<string.h>
#define SHIFT 3 

void encrypt(char* msg)
{
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + SHIFT;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + SHIFT;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
}


void decrypt(char* msg)
{
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - SHIFT;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - SHIFT;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
}

int main()
{
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    encrypt(message);
    printf("Encrypted message: %s\n", message);
    decrypt(message);
    printf("Decrypted message: %s\n", message);
    return 0;
}