//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>

void encrypt(char *input, int key){
    // check if the input string is empty
    if (*input == '\0'){
        return;
    }
    
    // add the key to the current character
    *input = (*input + key) % 256;
    
    // call the function recursively with the next character in the string
    encrypt(input+1, key);
}

void decrypt(char *input, int key){
    // check if the input string is empty
    if (*input == '\0'){
        return;
    }
    
    // subtract the key from the current character
    *input = (*input - key) % 256;
    
    // call the function recursively with the next character in the string
    decrypt(input+1, key);
}

int main(){
    char message[] = "Hello, world!";
    int key = 5;
    
    printf("Original message: %s\n", message);
    
    // encrypt the message
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    // decrypt the message
    decrypt(message, key);
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}