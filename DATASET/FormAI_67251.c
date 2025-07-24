//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey" // The key used for encryption and decryption

void encrypt(char *input, char *output){
    int i;
    for (i = 0; i < strlen(input); i++){
        output[i] = input[i] ^ KEY[i % strlen(KEY)]; // Applying XOR operation with the key
    }
}

void decrypt(char *input, char *output){
    int i;
    for (i = 0; i < strlen(input); i++){
        output[i] = input[i] ^ KEY[i % strlen(KEY)]; // Applying XOR operation with the key
    }
}

int main(){
    char input[100]; // The string to be encrypted
    char output[100]; // The encrypted string
    char decrypted[100]; // The decrypted string
    
    printf("Enter a string to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // Removing the new line character
    
    encrypt(input, output);
    printf("Encrypted string: %s\n", output);
    
    decrypt(output, decrypted);
    printf("Decrypted string: %s\n", decrypted);
    
    return 0;
}