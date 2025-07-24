//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 20

// Function to convert decimal to binary
char *decimal_to_binary(int n)
{
    char *binary_number = (char *) malloc(sizeof(char) * MAX_BINARY_LENGTH);
    int index = 0;
    int i = 0;
    while (n > 0) {
        binary_number[index++] = n % 2 + '0';
        n = n / 2;
    }
    for (i = index; i < MAX_BINARY_LENGTH; i++) {
        binary_number[i] = '0';
    }
    binary_number[MAX_BINARY_LENGTH - 1] = '\0';
    return binary_number;
}

// Function to convert binary to decimal
int binary_to_decimal(char *binary_number)
{
    int decimal_number = 0;
    int base = 1;
    int i = 0;
    for (i = strlen(binary_number) - 1; i >= 0; i--) {
        if (binary_number[i] == '1') {
            decimal_number += base;
        }
        base *= 2;
    }
    return decimal_number;
}

// Main function to test binary conversion
int main()
{
    int decimal_number = 125;
    char *binary_number = decimal_to_binary(decimal_number);
    printf("Decimal number: %d\n", decimal_number);
    printf("Binary number: %s\n", binary_number);
    printf("Decimal number from binary: %d\n", binary_to_decimal(binary_number));
    free(binary_number);
    return 0;
}