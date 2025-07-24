//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEED_LENGTH 100

void generateRandomSeed(char* seed);
void encrypt(char* plaintext, char* encrypted_text, char* key);
void decrypt(char* encrypted_text, char* plaintext, char* key);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <plaintext>\n", argv[0]);
        return EXIT_SUCCESS;
    }
    
    char* plaintext = argv[1];
    char seed[SEED_LENGTH];
    generateRandomSeed(seed);
    
    char key[SEED_LENGTH];
    srand(time(NULL));
    for (int i = 0; i < SEED_LENGTH; i++) {
        key[i] = rand() % 256;
    }
    
    char encrypted_text[strlen(plaintext)];
    encrypt(plaintext, encrypted_text, key);
    
    char decrypted_text[strlen(plaintext)];
    decrypt(encrypted_text, decrypted_text, key);
    
    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted text: %s\n", encrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);
    
    return EXIT_SUCCESS;
}

void generateRandomSeed(char* seed) {
    srand(time(NULL));
    for (int i = 0; i < SEED_LENGTH; i++) {
        seed[i] = rand() % 256;
    }
}

void encrypt(char* plaintext, char* encrypted_text, char* key) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        encrypted_text[i] = plaintext[i] ^ key[i % SEED_LENGTH];
    }
}

void decrypt(char* encrypted_text, char* plaintext, char* key) {
    int len = strlen(encrypted_text);
    for (int i = 0; i < len; i++) {
        plaintext[i] = encrypted_text[i] ^ key[i % SEED_LENGTH];
    }
}