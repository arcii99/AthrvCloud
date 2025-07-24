//FormAI DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 1024

char key[] = "mysecretkey"; // encryption key

// function to encrypt the input
void encrypt(char input[], char result[]) {
    int i, j = 0, len = strlen(input);
    for(i = 0; i < len; i++) {
        if(isalpha(input[i])) { // if character is alphabetic
            char c = toupper(input[i]) - 'A';
            char k = toupper(key[j]) - 'A';
            result[i] = (c + k) % 26 + 'A';
            j = (j + 1) % strlen(key); // move to next character in the key
        }
        else {
            result[i] = input[i];
        }
    }
    result[len] = '\0'; // add terminating null character
}

// function to decrypt the input
void decrypt(char input[], char result[]) {
    int i, j = 0, len = strlen(input);
    for(i = 0; i < len; i++) {
        if(isalpha(input[i])) { // if character is alphabetic
            char c = toupper(input[i]) - 'A';
            char k = toupper(key[j]) - 'A';
            result[i] = (c - k + 26) % 26 + 'A';
            j = (j + 1) % strlen(key); // move to next character in the key
        }
        else {
            result[i] = input[i];
        }
    }
    result[len] = '\0'; // add terminating null character
}

int main() {
    char input[MAX_INPUT_LEN], enc[MAX_INPUT_LEN], dec[MAX_INPUT_LEN];

    printf("Enter text to encrypt: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    encrypt(input, enc);
    printf("Encrypted text: %s\n", enc);

    decrypt(enc, dec);
    printf("Decrypted text: %s\n", dec);

    return 0;
}