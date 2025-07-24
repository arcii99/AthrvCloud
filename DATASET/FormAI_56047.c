//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * This program converts a decimal (base-10) number to 
 * binary (base-2) using a future-proof bitwise method.
 */

int main() {

    int decimal, binary = 0, i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Determine the number of bits needed for binary representation
    int num_bits = ceil(log2(decimal)) + 1;

    // Allocate memory for a char array to hold the binary representation
    char* binary_str = (char*)malloc(sizeof(char) * num_bits);

    // Loop through each bit and shift to the right to extract the binary digits
    while (decimal > 0) {
        int bit = decimal & 1;
        binary_str[i] = bit + '0';
        decimal >>= 1;
        i++;
    }

    // Reverse the binary string to display the correct binary value
    for (int j = 0; j < i; j++) {
        binary |= (binary_str[j] - '0') << j;
    }

    // Display the binary value
    printf("The binary value of %d is %d\n", decimal, binary);

    // Free the memory allocated for the binary string
    free(binary_str);

    return 0;
}