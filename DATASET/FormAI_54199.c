//FormAI DATASET v1.0 Category: QR code reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

/*
A function that checks if the input string contains only valid characters.
*/
bool isValidInput(char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
    }
    return true;
}

/*
A function that converts a binary string to an integer.
*/
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 1;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

/*
A function that reads the input from the user and checks if it is valid.
*/
void readInput(char* input) {
    printf("Enter a binary string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character from input
    if (!isValidInput(input)) {
        printf("Invalid input! Please enter a binary string.\n");
        readInput(input);
    }
}

/*
A function that decodes the QR code and prints the result.
*/
void decodeQrCode(char* input) {
    int code = binaryToDecimal(input);
    printf("The QR code is: %d\n", code);
}

int main() {
    // initialize input buffer and read input from user
    char input[MAX_INPUT_SIZE];
    readInput(input);

    // decode the QR code and print the result
    decodeQrCode(input);

    return 0;
}