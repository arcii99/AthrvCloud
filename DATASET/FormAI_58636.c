//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to convert character to binary
char *charToBinary(int num) {
    char *binary = (char*) malloc(9*sizeof(char));
    int i, j;
    for(i=7; i>=0; i--) {
        j = num >> i;
        if(j & 1) {
            *(binary + 7 - i) = '1';
        } else {
            *(binary + 7 - i) = '0';
        }
    }
    *(binary + 8) = '\0';
    return binary;
}

// function to convert binary to character
char binaryToChar(char *binary) {
    int i, j, num = 0;
    for(i=0; i<8; i++) {
        j = *(binary + i) - '0';
        num += j * pow(2, 7-i);
    }
    return (char) num;
}

// function to perform encryption
void encrypt(char *message, char *key) {
    int lenMessage = strlen(message), lenKey = strlen(key), i, j;
    char *binaryMessage, *binaryKey, *binaryOutput;
    printf("Encrypted message: ");
    for(i=0; i<lenMessage; i++) {
        binaryMessage = charToBinary(message[i]);
        binaryKey = charToBinary(key[i % lenKey]);
        binaryOutput = (char*) malloc(9*sizeof(char));
        for(j=0; j<8; j++) {
            if(binaryMessage[j] == binaryKey[j]) {
                *(binaryOutput + j) = '0';
            } else {
                *(binaryOutput + j) = '1';
            }
        }
        *(binaryOutput + 8) = '\0';
        printf("%c", binaryToChar(binaryOutput));
        free(binaryMessage);
        free(binaryKey);
        free(binaryOutput);
    }
    printf("\n");
}

// function to perform decryption
void decrypt(char *message, char *key) {
    int lenMessage = strlen(message), lenKey = strlen(key), i, j;
    char *binaryMessage, *binaryKey, *binaryOutput;
    printf("Decrypted message: ");
    for(i=0; i<lenMessage; i++) {
        binaryMessage = charToBinary(message[i]);
        binaryKey = charToBinary(key[i % lenKey]);
        binaryOutput = (char*) malloc(9*sizeof(char));
        for(j=0; j<8; j++) {
            if(binaryMessage[j] == binaryKey[j]) {
                *(binaryOutput + j) = '0';
            } else {
                *(binaryOutput + j) = '1';
            }
        }
        *(binaryOutput + 8) = '\0';
        printf("%c", binaryToChar(binaryOutput));
        free(binaryMessage);
        free(binaryKey);
        free(binaryOutput);
    }
    printf("\n");
}

// main function
int main() {
    char message[] = "Hello World!", key[] = "mykey";
    encrypt(message, key);
    decrypt("gejmYz[OQW", key);
    return 0;
}