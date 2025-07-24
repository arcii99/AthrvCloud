//FormAI DATASET v1.0 Category: Encryption ; Style: romantic
#include<stdio.h>
#include<string.h>

// XOR Encryption Function
void encrypt(char msg[], char key[]){
    int msgsize = strlen(msg);
    int keysize = strlen(key);
    for (int i=0; i<msgsize; i++){
        msg[i] = msg[i] ^ key[i % keysize];
    }
}

int main(){
    char msg[100];
    char key[100];
    
    printf("Enter message to encrypt: ");
    scanf("%s", msg);
    
    printf("Enter key: ");
    scanf("%s", key);
    
    encrypt(msg, key);
    
    printf("\nEncrypted message: %s", msg);
    
    return 0;
}