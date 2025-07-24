//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key){
    int length = strlen(message);
    for(int i = 0; i < length; i++){
        message[i] += key;
    }
}

void decrypt(char* message, int key){
    int length = strlen(message);
    for(int i = 0; i < length; i++){
        message[i] -= key;
    }
}

int main(){
    char message[100];
    int key;
    printf("Enter message: ");
    scanf("%[^\n]%*c", message);
    printf("Enter key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}