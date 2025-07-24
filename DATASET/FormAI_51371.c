//FormAI DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 0x1F

void encrypt(char *input, int key){
    int i = 0;
    while(input[i] != '\0'){
        input[i] = input[i] ^ key; //XOR operator (^) used to encrypt the input string
        i++;
    }
}

void decrypt(char *input, int key){
    encrypt(input, key); //Same function used to decrypt the input string
}

int main(){
    char input[100];
    printf("Enter a string to encrypt: ");
    fgets(input, 100, stdin); //Gets input from standard input

    encrypt(input, ENCRYPT_KEY); //Encrypting the input string
    
    printf("Encrypted string: %s\n", input);
    
    decrypt(input, ENCRYPT_KEY); //Decrypting the encrypted string
    
    printf("Decrypted string: %s\n", input);
    
    return 0;
}