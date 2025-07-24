//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int key_length;          
    char* key;              
}Key;

typedef struct {
    char* ciphertext;       
}Cipher;

void generate_key(Key* k) {
    srand(time(NULL));
    int key_length = rand() % 16 + 16;  
    k->key_length = key_length;
    k->key = (char*)malloc((key_length + 1) * sizeof(char));
    for(int i = 0; i < key_length; i++) {
        k->key[i] = (char)(rand() % 256); 
    }
    k->key[key_length] = '\0';
}

void encrypt(char* plaintext, Cipher* c, Key* k) {
    int len = strlen(plaintext);
    int key_length = k->key_length;
    char* ciphertext = (char*)malloc((len + 1) * sizeof(char));
    for(int i = 0; i < len; i++) {
        int j = i % key_length;
        ciphertext[i] = plaintext[i] ^ k->key[j];
    }
    ciphertext[len] = '\0';
    c->ciphertext = ciphertext;
}

int main() {
    Key k;
    generate_key(&k);
    char plaintext[] = "Hello, world!";
    Cipher c;
    encrypt(plaintext, &c, &k);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", c.ciphertext);
    free(k.key);
    free(c.ciphertext);
    return 0;
}