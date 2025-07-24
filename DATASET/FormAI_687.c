//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key){
    int len = strlen(message);
    char* cipher = (char*) malloc(len + 1);
    for(int i = 0; i < len; i++){
        cipher[i] = message[i] + key;
    }
    cipher[len] = '\0';
    return cipher;
}

int main(){
    char* message = "Hello, World!";
    int key = 5;
    char* cipher = encrypt(message, key);
    
    printf("Original Message: %s\n", message);
    printf("Key: %d\n", key);
    printf("Encrypted Message: %s\n", cipher);
    
    free(cipher);
    return 0;
}