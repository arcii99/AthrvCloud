//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum input length to be converted
#define MAX_INPUT_LENGTH 100

// function to convert the input decimal number to binary
char* decToBin(int num) {
    // allocate memory for the binary string
    char* binStr = (char*)malloc(sizeof(char) * (MAX_INPUT_LENGTH + 1));
    // initialize the binary string
    memset(binStr, 0, MAX_INPUT_LENGTH + 1);

    // loop through the number's bits
    for (int i = 7; i >= 0; i--) {
        // compute the i-th bit of the binary representation
        int bit = (num >> i) & 1;
        // add the bit to the binary string
        binStr[7 - i] = bit + '0';
    }

    // return the binary string
    return binStr;
}

int main() {
    // read the input decimal number from the user
    int num;
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &num);

    // convert the decimal number to binary
    char* binStr = decToBin(num);

    // print the binary string
    printf("The binary representation of %d is %s\n", num, binStr);

    // free the dynamically allocated memory
    free(binStr);

    return 0;
}