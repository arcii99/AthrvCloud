//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void divide(int a, int b);
int main()
{
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    divide(x, y);

    return 0;
}

void divide(int a, int b)
{
    if (b == 0)
    {
        fputs("Error: Cannot divide by zero\n", stderr);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("%d / %d = %.2f\n", a, b, (float)a / b);
    }
}