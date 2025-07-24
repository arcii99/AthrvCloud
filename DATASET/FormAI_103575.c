//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 100 // maximum input length

void convertToHex(char input[], int inputLength); // function prototype

int main() {
    char input[MAX_INPUT]; // input buffer
    int inputLength = 0; // length of input string

    printf("Please enter a string to convert to hex: ");
    fgets(input, MAX_INPUT, stdin); // read input string from stdin
    inputLength = strlen(input);

    // remove newline character from input string
    input[inputLength-1] = '\0';
    inputLength--;

    // convert input string to hex
    convertToHex(input, inputLength);

    return 0;
}

// function to convert string to hex
void convertToHex(char input[], int inputLength) {
    char hexOutput[MAX_INPUT*2]; // output buffer for hex
    int i, j;

    for (i = 0, j = 0; i < inputLength; i++, j+=2) {
        sprintf(hexOutput+j, "%02X", input[i]); // convert character to two-digit hex format
    }

    // print hex output
    printf("Hex output: 0x%s\n", hexOutput);
}