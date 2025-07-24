//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *s, int key){
    int i, len = strlen(s);
    for(i=0; i<len; i++){
        s[i] = s[i] + key;
    }
}

void decrypt(char *s, int key){
    int i, len = strlen(s);
    for(i=0; i<len; i++){
        s[i] = s[i] - key;
    }
}

int main(){
    //input
    char plaintext[100], ciphertext[100];
    int key, choice;
    printf("Enter the plaintext: ");
    scanf("%[^\n]s", plaintext);   //input string with spaces
    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    //encryption
    strcpy(ciphertext, plaintext);    //copy plaintext to ciphertext
    encrypt(ciphertext, key);    //encrypt the ciphertext

    printf("\nEncrypted Text: %s", ciphertext);

    //menu driven program for choice between encryption and decryption
    printf("\n\nDo you want to decrypt the text? (1/0): ");
    scanf("%d", &choice);

    if(choice==1){
        decrypt(ciphertext, key);
        printf("Decrypted Text: %s", ciphertext);
    }

    return 0;
}