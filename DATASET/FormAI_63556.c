//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>

// Function to print the pyramid using specified character
void print_pyramid(int rows, char c)
{
    int i, j, k;

    for (i = 1; i <= rows; i++)
    {
        // Print spaces
        for (k = i; k < rows; k++)
            printf(" ");

        // Print characters
        for (j = 1; j <= (2*i - 1); j++)
            printf("%c", c);

        // Move to next line
        printf("\n");
    }
}

int main()
{
    int rows;
    char c;

    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &rows);

    printf("Enter the character to use for the pyramid: ");
    scanf(" %c", &c);

    // Print the pyramid
    print_pyramid(rows, c);

    return 0;
}