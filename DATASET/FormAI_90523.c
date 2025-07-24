//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define KEY_LEN 10

// Prototype of the functions
unsigned char* encrypt(unsigned char*, unsigned char*);
void xor(unsigned char*, unsigned char*);

int main(){
    unsigned char plaintext[] = "Hello World!";
    unsigned char key[KEY_LEN] = "secretkey";

    unsigned char* ciphertext;

    ciphertext = encrypt(plaintext, key);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}

// Function to perform encryption
unsigned char* encrypt(unsigned char* plaintext, unsigned char* key){
    int i, j;
    unsigned char* ciphertext = strdup((char*) plaintext);
    int len = strlen((char*) plaintext);

    for (i = 0, j = 0; i < len; i++, j++){
        if (j == KEY_LEN) j = 0;

        xor(&ciphertext[i], &key[j]);
    }

    return ciphertext;
}

// Function to perform the bitwise XOR of two characters
void xor(unsigned char* a, unsigned char* b){
    *a ^= *b;
}