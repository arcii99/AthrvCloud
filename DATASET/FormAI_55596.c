//FormAI DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program converts a decimal number to binary
int main()
{
    printf("Welcome to the Binary Converter!\n");
    printf("Enter a decimal number: ");

    int decimal_num;
    scanf("%d", &decimal_num);

    int binary_num[32];
    int index = 0;

    // Convert decimal to binary
    while(decimal_num > 0)
    {
        binary_num[index] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        index++;
    }

    // Print binary number in reverse order
    printf("The binary equivalent is: ");
    for(int i = index-1; i >= 0; i--)
    {
        printf("%d", binary_num[i]);
    }
    printf("\n");

    return 0;
}