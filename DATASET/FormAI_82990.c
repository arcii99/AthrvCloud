//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char plaintext[], int key){
    int i;
    for(i=0;i<strlen(plaintext);i++){
        if(plaintext[i]>='a' && plaintext[i]<='z'){
            plaintext[i] = ((plaintext[i]-'a') + key)%26 + 'a';
        }
        else if(plaintext[i]>='A' && plaintext[i]<='Z'){
            plaintext[i] = ((plaintext[i]-'A') + key)%26 + 'A';
        }
    }
}

void decrypt(char ciphertext[], int key){
    int i;
    for(i=0;i<strlen(ciphertext);i++){
        if(ciphertext[i]>='a' && ciphertext[i]<='z'){
            ciphertext[i] = ((ciphertext[i]-'a') - key + 26)%26 + 'a';
        }
        else if(ciphertext[i]>='A' && ciphertext[i]<='Z'){
            ciphertext[i] = ((ciphertext[i]-'A') - key + 26)%26 + 'A';
        }
    }
}

int main(){
    char message[100];
    int key;
    printf("Enter the message to be encrypted (max 100 characters): ");
    fgets(message,100,stdin);
    printf("Enter the key (an integer from 1 to 25): ");
    scanf("%d",&key);
    encrypt(message,key);
    printf("The encrypted message is: %s\n",message);
    decrypt(message,key);
    printf("The decrypted message is: %s\n",message);
    return 0;
}