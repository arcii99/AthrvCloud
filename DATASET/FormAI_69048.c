//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

char plaintext[MAX_HEIGHT][MAX_WIDTH+1];
char cyphertext[MAX_HEIGHT][MAX_WIDTH+1];
int key[MAX_WIDTH];

void encrypt(char* input, char* output, int* k, int len){
    int i,j;
    for(i=0; i<len; i++){
        for(j=0; j<strlen(input); j++){
            if(key[i] == j%len){
                output[i] = input[j];
            }
        }
    }
}

void decrypt(char* input, char* output, int* k, int len){
    int i,j;
    for(i=0; i<len; i++){
        for(j=0; j<strlen(input); j++){
            if(key[j%len] == i){
                output[j] = input[i];
            }
        }
    }
}

int main(int argc, char** argv){
    char* input = "I am a chatbot";
    int len = strlen(input);

    // Generate a random key for the encryption
    int i;
    for(i=0; i<MAX_WIDTH; i++){
        key[i] = rand()%len;
    }

    // Fill the plaintext array with the input string
    for(i=0; i<MAX_HEIGHT; i++){
        strcpy(plaintext[i], input);
    }

    // Encrypt the plaintext into the cyphertext array
    for(i=0; i<MAX_HEIGHT; i++){
        encrypt(plaintext[i], cyphertext[i], key, len);
    }

    // Print out the cyphertext as ASCII art
    for(i=0; i<MAX_HEIGHT; i++){
        printf("%s\n", cyphertext[i]);
    }

    // Decrypt the cyphertext back into plaintext
    for(i=0; i<MAX_HEIGHT; i++){
        decrypt(cyphertext[i], plaintext[i], key, len);
    }

    // Print out the decrypted plaintext
    for(i=0; i<MAX_HEIGHT; i++){
        printf("%s\n", plaintext[i]);
    }

    return 0;
}