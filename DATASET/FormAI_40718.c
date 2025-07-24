//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

//function to encrypt the string
void encrypt(char* message, int shift_key){
    char ch;
    int i;
    for(i = 0; message[i] != '\0'; i++){
        ch = message[i];
        //encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + shift_key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
        //encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift_key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
    }
}

//function to decrypt the string
void decrypt(char* message, int shift_key){
    char ch;
    int i;
    for(i = 0; message[i] != '\0'; i++){
        ch = message[i];
        //decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - shift_key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
        //decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - shift_key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
    }
}
int main(){
    char message[100];
    int shift_key;
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter shift key: ");
    scanf("%d", &shift_key);
    encrypt(message, shift_key);
    printf("Encrypted Message: %s", message);
    decrypt(message, shift_key);
    printf("Decrypted Message: %s", message);
    return 0;
}