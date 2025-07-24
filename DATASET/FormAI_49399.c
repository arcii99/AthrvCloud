//FormAI DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 10
#define MAX_CODE_SIZE 100

struct Code {
    char symbol;
    int frequency;
    char code[MAX_CODE_SIZE];
};

typedef struct Code Code;

// Function to sort Code array based on frequency
void sort(Code codes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (codes[i].frequency < codes[j].frequency) {
                Code temp = codes[i];
                codes[i] = codes[j];
                codes[j] = temp;
            }
        }
    }
}

// Function to generate Huffman codes
void generateHuffmanCodes(Code codes[], int n) {
    int codeLength = 0;
    char code[MAX_CODE_SIZE];

    // Traverse Code array from highest to lowest frequency
    for (int i = 0; i < n; i++) {
        // Starting code is '1' for the least frequent symbol
        if (i == n - 1) {
            codeLength--;
            strcpy(codes[i].code, code);
            break;
        }

        // Add '0' or '1' to the code
        code[codeLength++] = '0';
        strcpy(codes[i].code, code);

        if (codeLength > 1) {
            // Add previous code to new code
            for (int j = i - 1; j >= 0; j--) {
                strcat(codes[i].code, codes[j].code);
            }
        }

        // Starting code for next symbol is the previous code plus '1'
        code[codeLength - 1] = '1';
    }
}

// Function to compress data using Huffman coding
void compress(char data[]) {
    Code codes[256] = {0};
    int n = 0;

    // Determine frequency of each symbol
    for (int i = 0; data[i] != '\0'; i++) {
        char symbol = data[i];
        int j = 0;

        // Check if symbol already exists in Code array
        for (; j < n; j++) {
            if (codes[j].symbol == symbol) {
                codes[j].frequency++;
                break;
            }
        }

        // Add new symbol to Code array
        if (j == n) {
            codes[j].symbol = symbol;
            codes[j].frequency = 1;
            n++;
        }
    }

    // Sort Code array based on frequency
    sort(codes, n);

    // Generate Huffman codes
    generateHuffmanCodes(codes, n);

    // Print Huffman codes
    printf("Huffman Codes:\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %s\n", codes[i].symbol, codes[i].code);
    }

    // Compress data using Huffman codes
    char compressedData[CHUNK_SIZE] = {0};
    int compressedDataIndex = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        char symbol = data[i];

        // Find code for current symbol
        for (int j = 0; j < n; j++) {
            if (codes[j].symbol == symbol) {
                // Copy code to compressedData
                strcat(compressedData, codes[j].code);
                compressedDataIndex += strlen(codes[j].code);

                // Add extra 0s at the end to fill out the last byte
                if (compressedDataIndex % 8 == 0 && i != strlen(data) - 1) {
                    compressedDataIndex = 0;
                    printf("%c", strtol(compressedData, 0, 2)); // Write compressedData to file
                    memset(compressedData, 0, CHUNK_SIZE);
                }
                break;
            }
        }
    }

    // Write remaining compressedData to file
    printf("%c", strtol(compressedData, 0, 2));

    printf("\nData compressed successfully!\n");
}

// Test program
int main() {
    char data[CHUNK_SIZE] = "Hello, World!";
    printf("Original Data:\n%s\n", data);
    compress(data);

    return 0;
}