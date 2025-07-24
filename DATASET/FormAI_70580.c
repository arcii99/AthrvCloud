//FormAI DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Recursive function to convert decimal number to binary
void decimalToBinary(int decimal, char* binary) {
    // Base case
    if (decimal == 0) {
        strcpy(binary, "0");
        return;
    }

    // Recursion
    decimalToBinary(decimal / 2, binary);
    char result[2];
    sprintf(result, "%d", decimal % 2);
    strcat(binary, result);
}

int main() {
    int decimal;
    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary using the recursive function
    char binary[32] = "";
    decimalToBinary(decimal, binary);
    printf("Binary equivalent: %s\n", binary);

    return 0;
}