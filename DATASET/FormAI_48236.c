//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLOCK_SIZE 128

// Define structs
typedef struct block_t{
    unsigned char bytes[BLOCK_SIZE];
} block_t;

typedef struct cipher_state_t{
    unsigned char key[BLOCK_SIZE];
} cipher_state_t;

// Functions to set up cipher state
void init_cipher_state(cipher_state_t *state, const unsigned char *key){
    memcpy(state->key, key, BLOCK_SIZE);
}

void generate_random_key(cipher_state_t *state){
    for(int i = 0; i < BLOCK_SIZE; i++){
        state->key[i] = rand() % 256;
    }
}

// Cipher functions
void encrypt_block(block_t *block, cipher_state_t *state){
    for(int i = 0; i < BLOCK_SIZE; i++){
        block->bytes[i] = block->bytes[i] ^ state->key[i];
    }
}

void decrypt_block(block_t *block, cipher_state_t *state){
    for(int i = 0; i < BLOCK_SIZE; i++){
        block->bytes[i] = block->bytes[i] ^ state->key[i];
    }
}

// Main function
int main(){

    // Declare and initialize variables
    block_t block;
    cipher_state_t state;
    bool encrypt = true;
    char input[256];

    // Ask user for input
    printf("Enter a message to encrypt/decrypt: ");
    fgets(input, 256, stdin);
    int input_length = strlen(input);

    // Set up cipher state
    generate_random_key(&state);

    // Encrypt or decrypt message
    for(int i = 0; i < input_length; i += BLOCK_SIZE){
        memcpy(block.bytes, input + i, BLOCK_SIZE);
        if(encrypt){
            encrypt_block(&block, &state);
        } else {
            decrypt_block(&block, &state);
        }
        memcpy(input + i, block.bytes, BLOCK_SIZE);
    }

    // Print encrypted or decrypted message
    printf("Your %s message is: %s\n", encrypt ? "encrypted" : "decrypted", input);

    return 0;
}