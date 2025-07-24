//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x75 //Key for encryption

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Error: Please specify a string to encrypt.\n");
        return 1;
    }

    char *inputString = argv[1];
    int stringLength = strlen(inputString);

    int i;
    for (i = 0; i < stringLength; i++) {
        char currentChar = inputString[i];
        char encryptedChar = currentChar ^ KEY; //XOR the character with the key
        printf("%02x", encryptedChar); //Print out the encrypted value as a hexadecimal string
    }

    printf("\n");
    return 0;
}