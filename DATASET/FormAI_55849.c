//FormAI DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32 // maximum bits for a binary number

int main()
{
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    int binary[MAX_BITS], i = 0;
    while (num > 0 && i < MAX_BITS)
    {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    // Print binary conversion
    printf("Binary conversion: ");
    if (i == 0)
    {
        printf("0");
    }
    else
    {
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", binary[j]);
        }
    }
    printf("\n");

    return 0;
}