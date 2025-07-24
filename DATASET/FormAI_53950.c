//FormAI DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key){
    int length = strlen(message);
    for(int i = 0; i < length; i++){
        message[i] += key;
    }
}

void decrypt(char message[], int key){
    int length = strlen(message);
    for(int i = 0; i < length; i++){
        message[i] -= key;
    }
}

int main(){
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    getchar();
    
    encrypt(message, key);
    printf("Encrypted Message: %s", message);
    
    decrypt(message, key);
    printf("Decrypted Message: %s", message);
    
    return 0;
}