//FormAI DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
char* toBinary(int n)
{
    char* binary = malloc(33 * sizeof(char)); // Allocate memory for binary string

    /* Check if the decimal number is negative */
    if (n < 0){
        n = -n; // Get the absolute value of the negative decimal number
        strcpy(binary, "1"); // If negative, set the first bit to 1
    } 
    else{
        strcpy(binary, "0"); // If positive, set the first bit to 0
    }

    /* Convert decimal to binary */
    int i = 30; // Index for binary string
    while (n > 0){
        binary[i] = (n % 2) + '0'; // Calculate the binary digit
        n = n / 2; // Divide decimal by 2
        i--;
    }
    binary[31] = '\0'; // Add null terminator to binary string
    return binary;
}

int main()
{
    int decimal;
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);

    char* binary = toBinary(decimal);
    printf("Binary representation: %s\n", binary);

    free(binary); // Free memory allocated for binary string
    return 0;
}