//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_INPUT_LENGTH 32

void printResult(int binary[], int binaryLength);

int main() {
    char inputStr[MAX_INPUT_LENGTH];
    int base = 2;
    bool isValidInput = false;
    bool isNegative = false;

    while (!isValidInput) {
        printf("Enter a decimal number: ");
        fgets(inputStr, MAX_INPUT_LENGTH, stdin);

        // Check if input is negative
        if (inputStr[0] == '-') {
            isNegative = true;
            strcpy(inputStr, inputStr + 1);
        }

        // Check if input is valid
        isValidInput = true;
        int inputLength = strlen(inputStr) - 1;
        for (int i = 0; i < inputLength; ++i) {
            if (inputStr[i] < '0' || inputStr[i] > '9') {
                printf("Invalid input: %s\n", inputStr);
                isValidInput = false;
                break;
            }
        }
    }

    int input = atoi(inputStr);

    // Handle negative input
    if (isNegative) {
        printf("-");
        input = abs(input);
    }

    // Get binary representation
    int binary[MAX_INPUT_LENGTH];
    int binaryLength = 0;
    while (input > 0) {
        binary[binaryLength] = input % base;
        input = input / base;
        ++binaryLength;
    }

    // Print binary representation
    printResult(binary, binaryLength);

    return 0;
}

void printResult(int binary[], int binaryLength) {
    printf("Binary representation: ");

    // Print binary digits in reverse order
    for (int i = binaryLength - 1; i >= 0; --i) {
        printf("%d", binary[i]);
    }

    printf("\n");
}