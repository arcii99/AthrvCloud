//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int decimalNumber)
{
    int binaryNumber[100], index=0;
        
    while(decimalNumber > 0)
    {
        binaryNumber[index] = decimalNumber % 2;
        index++;
        decimalNumber /= 2;
    }

    printf("\nBinary equivalent: ");
    for(int i = index-1; i >= 0; i--)
        printf("%d", binaryNumber[i]);
}

int main()
{
    int decimalNumber;
    char input[10];
    printf("*** Decimal to Binary Converter ***\n");
    while(1)
    {
        printf("\nEnter a decimal number (q to quit): ");
        fgets(input, 10, stdin);
        if(strcmp(input, "q\n") == 0 || strcmp(input, "Q\n") == 0)
            exit(0);
        decimalNumber = atoi(input);
        if(decimalNumber <= 0)
        {
            printf("Input must be a positive integer.\n");
            continue;
        }
        convertToBinary(decimalNumber);
    }
    return 0;
}