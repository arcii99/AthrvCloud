//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *key = "secretkey"; //the encryption key

void encrypt(char *input, char *output){
    int keylen = strlen(key);
    int inputlen = strlen(input);

    for (int i = 0; i < inputlen; i++){
        output[i] = input[i] ^ key[i%keylen]; //xor each character with the corresponding character in the key
    }

    output[inputlen] = '\0'; //add the null terminator to the end of the output string
}

void decrypt(char *input, char *output){
    int keylen = strlen(key);
    int inputlen = strlen(input);

    for (int i = 0; i < inputlen; i++){
        output[i] = input[i] ^ key[i%keylen]; //same process as encryption
    }

    output[inputlen] = '\0'; //add the null terminator to the end of the output string
}

int main(){
    char input[100];
    char output[100];
    char decrypted[100];

    printf("Enter a string to encrypt: ");
    scanf("%s", input);

    encrypt(input, output);

    printf("Encrypted string: %s\n", output);

    decrypt(output, decrypted);

    printf("Decrypted string: %s\n", decrypted);

    return 0;
}