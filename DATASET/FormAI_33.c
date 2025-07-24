//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *message, int key){
    int i = 0;
    while(message[i] != '\0'){
        message[i] = message[i] + key; //shift each character by key positions
        i++;
    }
}

void decrypt(char *message, int key){
    int i = 0;
    while(message[i] != '\0'){
        message[i] = message[i] - key; //shift each character back to original position
        i++;
    }
}

int main(){
    char message[100];
    int key, choice;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);
    printf("Enter key value: ");
    scanf("%d", &key);
    
    printf("\nOriginal message: %s", message);
    
    encrypt(message, key);
    printf("\nEncrypted message: %s", message);

    decrypt(message, key); //decrypting the message back to original
    printf("\nDecrypted message: %s", message);

    return 0;
}