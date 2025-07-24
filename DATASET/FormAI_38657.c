//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h> // For input and output operations

void binary_converter(int num)
{
    int binary[32]; // Initialize an array to hold binary values
    int i = 0; // Initialize counter

    while (num > 0) {
        binary[i] = num % 2; // Get binary remainder
        num = num / 2; // Divide number by 2
        i++; // Increment counter
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]); // Print binary value
    }
    
    printf("\n"); // Add a newline for clarity
}

int main() {
    int input;

    printf("Enter a decimal value: ");
    scanf("%d", &input);

    printf("Binary representation: ");
    binary_converter(input);

    return 0;
}