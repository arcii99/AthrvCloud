//FormAI DATASET v1.0 Category: modern Encryption ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char* input, int encryption_key){

    for(int i=0;i<strlen(input);i++){
        // shift the ascii value by the encryption key
        input[i] = input[i] + encryption_key;
    }
}

void decrypt(char* input, int decryption_key){

    for(int i=0;i<strlen(input);i++){
        // shift the ascii value back by the decryption key
        input[i] = input[i] - decryption_key;
    }
}

int main(){
    char input_string[100];
    int encryption_key, decryption_key;
    printf("Enter the string to encrypt: ");
    scanf("%s", input_string);

    printf("Enter the encryption key: ");
    scanf("%d",&encryption_key);

    // Encrypt the input string
    encrypt(input_string, encryption_key);

    printf("Encrypted String: %s\n", input_string);

    // Prompt user for decryption key and decrypt the encrypted string
    printf("Enter the decryption key: ");
    scanf("%d",&decryption_key);

    decrypt(input_string, decryption_key);

    printf("Decrypted String: %s\n", input_string);

    return 0;
}