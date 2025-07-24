//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>

// Function to convert decimal to binary
void decToBin(int decimal)
{
    // Array to store binary number
    int binary[1000];
    int index = 0;

    // Base case
    if (decimal <= 0)
    {
        return;
    }

    // Divide decimal by 2 repeatedly
    while (decimal > 0)
    {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    // Print binary in reverse order
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("The binary representation of %d is: ", decimal);
    decToBin(decimal);

    return 0;
}