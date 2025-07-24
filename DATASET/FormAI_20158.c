//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* This program converts a decimal value to its binary representation */

int main() {
    int decimal_number, binary_number[INT_MAX], i = 0;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    // Converting decimal to binary
    while(decimal_number > 0) {
        binary_number[i] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        i++;
    }
    
    // Printing binary number in reverse order
    printf("The binary representation of the given decimal number is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binary_number[j]);
    }
    
    return 0;
}