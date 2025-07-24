//FormAI DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10000
#define MAX_OUTPUT_SIZE 5000

// Function to convert integer to binary string
void toBinary(int n, char* binaryStr) {
    int index = 0;
    while(n > 0) {
        binaryStr[index++] = n%2 + '0';
        n /= 2;
    }
    binaryStr[index] = '\0';
}

// Compression function that converts a string to binary and compresses it
void compress(char* inputString, char* compressedString) {
    char binaryStr[MAX_BUFFER_SIZE];
    int k = 0, index = 0;

    for(int i=0; i<strlen(inputString); i++) {
        toBinary(inputString[i], binaryStr);
        for(int j=0; j<8; j++) {
            compressedString[k++] = binaryStr[j];
            if(k == MAX_OUTPUT_SIZE)
                break;
        }
        if(k == MAX_OUTPUT_SIZE)
            break;
    }
    compressedString[k] = '\0';
}

// Decompression function that converts compressed binary string to original string
void decompress(char* compressedString, char* decompressedString) {
    int len = strlen(compressedString);
    int index = 0, decimalValue = 0, base = 1;

    for(int i=0; i<len; i++) {
        if(compressedString[i] == '1') {
            decimalValue += base;
        }
        base *= 2;
        if((i+1)%8 == 0) {
            decompressedString[index++] = decimalValue;
            decimalValue = 0;
            base = 1;
        }
    }
    decompressedString[index] = '\0';
}

int main() {
    char inputString[MAX_BUFFER_SIZE], compressedString[MAX_OUTPUT_SIZE], decompressedString[MAX_BUFFER_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%[^\n]%*c", inputString);

    compress(inputString, compressedString);

    printf("\nCompressed String: %s\n", compressedString);

    decompress(compressedString, decompressedString);

    printf("\nDecompressed String: %s\n", decompressedString);

    return 0;
}