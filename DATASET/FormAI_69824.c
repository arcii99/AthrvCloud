//FormAI DATASET v1.0 Category: Modern Encryption ; Style: realistic
#include<stdio.h>
#include<string.h>

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main(){
    char message[100];
    int key;
    int choice;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]",message);
    printf("Enter key (1-25): ");
    scanf("%d",&key);

    printf("\n1. Encrypt Message\n2. Decrypt Message\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1: encrypt(message,key); break;
        case 2: decrypt(message,key); break;
        default: printf("Invalid choice.\n");
    }

    return 0;
}

void encrypt(char *message, int key){
    int i;
    char ch;

    for(i=0; message[i]!='\0'; i++){
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

    printf("Encrypted message: %s\n",message);
}

void decrypt(char *message, int key){
    int i;
    char ch;

    for(i=0; message[i]!='\0'; i++){
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

    printf("Decrypted message: %s\n",message);
}