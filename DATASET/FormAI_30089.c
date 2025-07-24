//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>

#define MESSAGE_LENGTH 16

int main(){
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char message[MESSAGE_LENGTH];
    unsigned char encrypted[MESSAGE_LENGTH];
    unsigned char decrypted[MESSAGE_LENGTH];
    AES_KEY aes_key;

    // Initialize random number generator for key and iv
    srand(time(NULL));
    rand_array(key, AES_BLOCK_SIZE);
    rand_array(iv, AES_BLOCK_SIZE);

    // Initialize message with some text
    strcpy(message, "Hello, world!");

    // Encrypt message using AES algorithm
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(message, encrypted, MESSAGE_LENGTH, &aes_key, iv, AES_ENCRYPT);

    // Print encrypted message and key
    printf("Encrypted message: ");
    print_array(encrypted, MESSAGE_LENGTH);
    printf("Key: ");
    print_array(key, AES_BLOCK_SIZE);

    // Decrypt message using AES algorithm
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(encrypted, decrypted, MESSAGE_LENGTH, &aes_key, iv, AES_DECRYPT);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}

// Function to generate a random array of bytes
void rand_array(unsigned char* array, int length){
    int i;
    for(i=0; i<length; i++){
        array[i] = rand() % 256;
    }
}

// Function to print an array of bytes
void print_array(unsigned char* array, int length){
    int i;
    for(i=0; i<length; i++){
        printf("%02X ", array[i]);
    }
    printf("\n");
}