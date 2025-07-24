//FormAI DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void decToBin(int decimal) {
    int binary[32]; // array to hold binary digits
    int i = 0; // counter variable for binary array
    
    // loop to convert decimal to binary digits
    while (decimal > 0) {
        binary[i] = decimal % 2; // calculate binary digit
        decimal /= 2; // divide decimal by 2
        i++; // increment binary array counter
    }
    
    // loop to print binary digits in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int decimal;
    
    // prompt user for decimal input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    // check if decimal is non-negative
    if (decimal < 0) {
        printf("Error: decimal number must be non-negative.");
        exit(0);
    }
    
    // check if decimal is zero
    if (decimal == 0) {
        printf("Binary number: 0");
        exit(0);
    }
    
    // convert decimal to binary and print result
    printf("Binary number: ");
    decToBin(decimal);
    
    return 0;
}