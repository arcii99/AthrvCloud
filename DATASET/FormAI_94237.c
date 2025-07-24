//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include<stdlib.h>
#include<stdio.h>

int main(){
    char message[100], encrypt[100], decrypt[100];
    int key=5;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); //take input from user

    for(int i=0; i<strlen(message); i++){
        encrypt[i] = message[i] + key; //encrypt each character using the key
    }
    printf("Encrypted message: %s", encrypt); //print the encrypted message

    for(int i=0; i<strlen(encrypt); i++){
        decrypt[i] = encrypt[i] - key; //decrypt each character using the key
    }
    printf("Decrypted message: %s", decrypt); //print the decrypted message

    return 0;
}