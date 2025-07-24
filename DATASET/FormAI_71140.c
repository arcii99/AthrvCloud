//FormAI DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal_number, int* binary_array)
{
    int quotient = decimal_number;
    int i = 0;
    
    while (quotient != 0)
    {
        binary_array[i++] = quotient % 2;
        quotient = quotient / 2;
    }
}

// Function to print binary array
void print_binary_array(int* binary_array, int size)
{
    for (int i = size-1; i >= 0; i--)
    {
        printf("%d", binary_array[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int decimal_number;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);
    
    int binary_array[32]; // We assume integer has 32 bits
    
    decimal_to_binary(decimal_number, &binary_array);
    
    printf("Binary representation of %d: ", decimal_number);
    print_binary_array(binary_array, sizeof(binary_array)/sizeof(int));
    
    return 0;
}