//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *str){
    int i, n = strlen(str);
    for(i=0; i<n; i++){
        str[i] = str[i] + 3; 
    }
}

void decrypt(char *str){
    int i, n = strlen(str);
    for(i=0; i<n; i++){
        str[i] = str[i] - 3; 
    }
}

int main(){
    char msg[100];
    
    printf("Enter message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);
    
    // Removing newline character
    msg[strcspn(msg, "\n")] = 0;
    
    // Encrypting message
    encrypt(msg);
    printf("Encrypted message: %s\n", msg);
    
    // Decrypting message
    decrypt(msg);
    printf("Decrypted message: %s\n", msg);
    
    return 0;
}