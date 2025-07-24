//FormAI DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_first_half(int size);
void print_second_half(int size);

int main()
{
    int size = 7; // Size of the pattern

    print_first_half(size);
    print_second_half(size);

    printf("\n");
    return 0;
}

// Prints the first half of the pattern
void print_first_half(int size)
{
    int i, j;
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= (size - i); j++)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%c", '*');

        printf("\n");
    }
}

// Prints the second half of the pattern
void print_second_half(int size)
{
    int i, j;
    for (i = size - 1; i >= 1; i--)
    {
        for (j = 1; j <= (size - i); j++)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%c", '*');

        printf("\n");
    }
}