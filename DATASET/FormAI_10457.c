//FormAI DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("Welcome to the Binary Converter!\n");
    printf("Enter a decimal number: ");

    int decimalInput;
    scanf("%d", &decimalInput);

    int binaryOutput[32];
    int binaryIndex = 0;

    while (decimalInput > 0)
    {
        binaryOutput[binaryIndex] = decimalInput % 2;
        decimalInput = decimalInput / 2;
        binaryIndex++;
    }

    printf("Binary output: ");
    for (int i = binaryIndex - 1; i >= 0; i--)
    {
        printf("%d", binaryOutput[i]);
    }
    printf("\n");

    printf("Would you like to convert another number? (y/n)\n");
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y')
    {
        system("clear || cls");
        main();
    }
    else
    {
        printf("Thank you for using the Binary Converter!\n");
        return 0;
    }
}