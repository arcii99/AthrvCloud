//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void encrypt(char* message, int key){
    for(int i = 0; message[i] != '\0'; ++i){
        message[i] += key;
    }
}

void decrypt(char* message, int key){
    for(int i = 0; message[i] != '\0'; ++i){
        message[i] -= key;
    }
}

int main(){
    char message[1000];
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    
    printf("Enter a key: ");
    scanf("%d", &key);
    
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    
    return 0;
}