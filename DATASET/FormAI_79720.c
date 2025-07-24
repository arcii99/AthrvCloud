//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables
    int decimal, binaryNum = 0, remainder, i = 0;
    
    // Prompt user for decimal input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    // Convert decimal to binary
    while(decimal != 0) {
        remainder = decimal % 2;
        binaryNum += remainder * pow(10, i);
        decimal /= 2;
        i++;
    }
    
    // Print the binary number
    printf("The binary conversion of %d is %d\n", decimal, binaryNum);
    
    return 0;
}