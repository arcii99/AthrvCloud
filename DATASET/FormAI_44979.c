//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>

// Define a function to calculate the power of a number
int power(int base, int exponent) {
    int result = 1;
    
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    
    return result;
}

int main() {
    // Declare variables
    int decimalNumber, temp, binaryNumber = 0, digit, position = 1;
    
    // Prompt user for decimal number input
    printf("Enter a Decimal Number: ");
    scanf("%d", &decimalNumber);
    
    // Store the decimal number in a temporary variable
    temp = decimalNumber;
    
    // Convert decimal to binary
    while(temp != 0) {
        digit = temp % 2;
        binaryNumber += digit * power(10, position - 1);
        temp /= 2;
        position++;
    }
    
    // Print the binary equivalent
    printf("Binary Equivalent of %d is %d\n", decimalNumber, binaryNumber);
    
    return 0;
}