//FormAI DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *data, int key){
    int len = strlen(data);
    for(int i = 0; i < len; i++){
        // Perform XOR operation on each character with the key
        data[i] = data[i] ^ key;
    }
}

void decrypt(char *data, int key){
    int len = strlen(data);
    for(int i = 0; i < len; i++){
        // Perform XOR operation on each character with the key
        data[i] = data[i] ^ key;
    }
}

int main(){
    // initialize key and data variables
    char data[100];
    int key;
    
    // get input from user
    printf("Enter data to encrypt: ");
    scanf("%[^\n]s", data);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    // encrypt the data using the key
    encrypt(data, key);
    
    // print the encrypted data
    printf("Encrypted data: %s\n", data);
    
    // decrypt the data using the key
    decrypt(data, key);
    
    // print the decrypted data
    printf("Decrypted data: %s\n", data);
    
    return 0;
}