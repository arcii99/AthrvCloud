//FormAI DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>

int main() 
{
    int decimal, binaryNumber = 0, remainder, factor = 1;
    printf("Enter decimal number: ");
    scanf("%d", &decimal);
    while(decimal != 0) 
    {
        remainder = decimal % 2;
        binaryNumber = binaryNumber + remainder * factor;
        factor = factor * 10;
        decimal = decimal / 2;
    }
    printf("The binary equivalent of the entered decimal number is: %d\n", binaryNumber);
    return 0;
}