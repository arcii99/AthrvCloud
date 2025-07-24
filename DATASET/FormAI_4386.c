//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* input, char* key){
    int i, j;
    int input_length = strlen(input);
    int key_length = strlen(key);
    for(i=0, j=0; i<input_length; i++, j++){
        if(j == key_length){
            j = 0;
        }
        input[i] = input[i] + key[j];
    }
}

void decrypt(char* input, char* key){
    int i, j;
    int input_length = strlen(input);
    int key_length = strlen(key);
    for(i=0, j=0; i<input_length; i++, j++){
        if(j == key_length){
            j = 0;
        }
        input[i] = input[i] - key[j];
    }
}

int main(){
    char input[256];
    char key[256];
    printf("Enter the input string: ");
    fgets(input, 256, stdin);
    printf("Enter the key string: ");
    fgets(key, 256, stdin);
    input[strcspn(input, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    printf("Original input: %s\n", input);
    printf("Original key: %s\n", key);
    encrypt(input, key);
    printf("Encrypted input: %s\n", input);
    decrypt(input, key);
    printf("Decrypted input: %s\n", input);
    return 0;
}