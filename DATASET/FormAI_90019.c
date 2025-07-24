//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void VigEncrypt(char *plainText,char *key,char *cipherText){
    int keyLength = strlen(key), plainTextLength = strlen(plainText), i, j;
    char keyStream[keyLength];
  
    //generating the key stream
    for(i=0,j=0;i<keyLength; i++,j++){
        if(j==plainTextLength){
            j=0;
        }
        keyStream[i]=key[j];
    }

    //encrypting the plain text
    for(i=0;i<plainTextLength;i++){
        cipherText[i]=((plainText[i]+keyStream[i])%26) + 'A';
    }
}

int main(){
    char plainText[100];
    printf("Enter the plain text: ");
    scanf("%[^\n]%*c",plainText); //accepting the text input

    char key[100];
    printf("Enter the key: ");
    scanf("%[^\n]%*c",key); //accepting the key input

    char cipherText[100];
    VigEncrypt(plainText,key,cipherText); //calling the function to encrypt the plain text
    
    printf("\nEncrypted text: %s\n", cipherText); //printing the encrypted text
    
    return 0;
}