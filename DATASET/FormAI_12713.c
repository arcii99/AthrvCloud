//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SHIFT 3 // define shift value

void encrypt(char* message){
    int i;
    char ch;
    for(i=0; message[i] != '\0'; i++){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){ // lowercase letters
            ch = ch + SHIFT;    // shift the letter by the value
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){ // uppercase letters
            ch = ch + SHIFT;    // shift the letter by the value
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}


void decrypt(char* message){
    int i;
    char ch;
    for(i=0; message[i] != '\0'; i++){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){ // lowercase letters
            ch = ch - SHIFT;    // de-shift the letter
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){ // uppercase letters
            ch = ch - SHIFT;    // de-shift the letter
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

int main(){
    char message[1000];
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin); // read message from user
    
    printf("\nEncrypting message...");
    encrypt(message);
    printf("\nEncrypted message: %s", message);
    
    printf("\nDecrypting message...");
    decrypt(message);
    printf("\nDecrypted message: %s", message);

    return 0;
}