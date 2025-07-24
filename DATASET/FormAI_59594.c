//FormAI DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate random keys
void generate_key(int key[], int key_size){
    int i;
    for(i = 0; i < key_size; ++i){
        key[i] = rand() % 256;
    }
}

// Function to encrypt and decrypt message
void encrypt_decrypt(char message[], int key[], int key_size){
    int i;
    int j = 0;
    for(i = 0; message[i] != '\0'; i++){
        message[i] ^= key[j % key_size];
        j++;
    }
}

int main(){
    char message[100];
    int key_size = 16;
    int key[key_size];

    // Read message from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    // Generate random key
    generate_key(key, key_size);

    // Encrypt message
    encrypt_decrypt(message, key, key_size);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    encrypt_decrypt(message, key, key_size);
    printf("Decrypted message: %s\n", message);

    return 0;
}