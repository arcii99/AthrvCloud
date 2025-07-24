//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int x, y, result;

    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2)
    {
        fprintf(stderr, "Error: Invalid input. Please enter two integers.\n");
        exit(EXIT_FAILURE);
    }

    if (y == 0)
    {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }

    result = x / y;

    printf("%d / %d = %d\n", x, y, result);

    if (errno == ERANGE)
    {
        fprintf(stderr, "Error: Result out of range.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}