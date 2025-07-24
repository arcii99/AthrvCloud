//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_key(int key[], int length){
    //helper function to generate a random key
    int i;
    for(i=0;i<length;i++){
        key[i] = rand() % 128;
    }
}

void encrypt(char* plaintext, int key[], int length){
    //function to encrypt the plaintext using the key
    int i;
    for(i=0;i<strlen(plaintext);i++){
        plaintext[i] = plaintext[i] ^ key[i%length];
    }
}

void decrypt(char* ciphertext, int key[], int length){
    //function to decrypt the ciphertext using the key
    int i;
    for(i=0;i<strlen(ciphertext);i++){
        ciphertext[i] = ciphertext[i] ^ key[i%length];
    }
}

int main(){
    char plaintext[100];
    char ciphertext[100];
    int key[10];
    int key_length = 10;

    //get input from the user
    printf("Enter the plaintext: ");
    fgets(plaintext, 100, stdin);

    //generate a random key
    generate_key(key, key_length);

    //encrypt the plaintext using the key
    encrypt(plaintext, key, key_length);

    //print the encrypted ciphertext
    printf("\nEncrypted ciphertext: %s\n", plaintext);

    //decrypt the ciphertext using the key
    decrypt(plaintext, key, key_length);

    //print the decrypted plaintext
    printf("\nDecrypted plaintext: %s\n", plaintext);

    return 0;
}