//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

void printC(int length, int height, int currentHeight)
{
    if (currentHeight == 0 || currentHeight == height - 1)
    {
        // Print top and bottom horizontal lines
        for (int i = 0; i < length; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    else
    {
        // Print left vertical line
        printf("*\n");
    }

    if (currentHeight < height - 1)
    {
        // Move to next row and continue printing
        printC(length, height, currentHeight + 1);
    }
}

int main()
{
    int length, height;

    printf("Enter the length of C: ");
    scanf("%d", &length);

    printf("Enter the height of C: ");
    scanf("%d", &height);

    printf("\n");

    printC(length, height, 0);

    return 0;
}