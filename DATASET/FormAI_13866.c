//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
// Recursive Hexadecimal Converter

#include <stdio.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char* hexadecimal) {

    // Array of hexadecimal characters
    char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Base case
    if(decimal == 0) {
        *hexadecimal = '\0';
        return;
    }
    
    // Recursive call
    decimalToHexadecimal(decimal / 16, hexadecimal);
    
    // Append hexadecimal digit to result
    size_t length = strlen(hexadecimal);
    *(hexadecimal + length) = hexa[decimal % 16];
    *(hexadecimal + length + 1) = '\0';
}

int main() {
    int decimal;
    char hexadecimal[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to hexadecimal recursively
    decimalToHexadecimal(decimal, hexadecimal);

    printf("Hexadecimal equivalent: %s", hexadecimal);
    return 0;
}