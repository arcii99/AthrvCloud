//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define KEY 2

//function to encrypt message
void encrypt(char message[], int key){
    for(int i=0; i<strlen(message); i++){
        char ch = message[i];
        //only encrypt alphabets
        if(isalpha(ch)){
            ch = toupper(ch);
            message[i] = ((ch-'A') + key) % 26 + 'A';
        }
    }
}

//function to decrypt message
void decrypt(char message[], int key){
    for(int i=0; i<strlen(message); i++){
        char ch = message[i];
        //only decrypt alphabets
        if(isalpha(ch)){
            ch = toupper(ch);
            int temp = ch-'A'-key;
            if(temp<0){
                temp = 26 + temp;
            }
            message[i] = temp + 'A';
        }
    }
}

int main(){
    char message[100];
    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message); //accepts string with spaces
    encrypt(message, KEY);
    printf("Encrypted message: %s\n", message);
    decrypt(message, KEY);
    printf("Decrypted message: %s\n", message);
    return 0;
}