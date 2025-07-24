//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Binary Converter program! \n");
    printf("This program will convert any decimal number to its binary equivalent. \n");
    printf("Please enter a positive integer: ");

    int decimalNumber = 0;
    scanf("%d", &decimalNumber);

    if (decimalNumber <= 0)
    {
        printf("Oops! You did not enter a positive integer.\n");
        printf("I'm not mad, just disappointed. Try again later. Goodbye! \n");

        return 0;
    }

    int binaryNumber[32];
    int index = 0;

    while (decimalNumber > 0)
    {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index++;
    }

    printf("The binary equivalent of your number is: ");

    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binaryNumber[i]);
    }

    printf("\nThank you for using our Binary Converter program. \n");
    printf("Now go out there and confuse your friends by speaking binary! \n");

    return 0;
}