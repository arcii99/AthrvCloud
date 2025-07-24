//FormAI DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Binary Converter program!\n\n");

    int number;
    printf("Please enter the number you want to convert to binary: ");
    scanf("%d", &number);

    printf("\nThe decimal number %d in binary is: ", number);
    int binary[32];
    int i = 0;
    while (number > 0)
    {
        binary[i] = number % 2;
        number = number / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n\nWow, wasn't that amazing?! You can now convert any decimal number to binary with ease using this program.\n");

    return 0;
}