//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAXLEN 1024

// function prototypes
void encrypt(char* input, char* output, int key);
void decrypt(char* input, char* output, int key);

// main function
int main() {
    char input[MAXLEN], output[MAXLEN];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(input, MAXLEN, stdin);

    // generate a random encryption key
    srand(time(NULL));
    key = (rand() % 100) + 1;

    // encrypt the input string
    encrypt(input, output, key);
    printf("Encrypted string: %s\n", output);

    // decrypt the encrypted string
    decrypt(output, input, key);
    printf("Decrypted string: %s\n", input);

    return 0;
}

// encryption function
void encrypt(char* input, char* output, int key) {
    int len = strlen(input);
    int i;

    for (i = 0; i < len; i++) {
        output[i] = fmod((double)input[i] + (double)key, 128.0);
    }

    output[i] = '\0';
}

// decryption function
void decrypt(char* input, char* output, int key) {
    int len = strlen(input);
    int i;

    for (i = 0; i < len; i++) {
        output[i] = fmod((double)input[i] - (double)key, 128.0);
    }

    output[i] = '\0';
}