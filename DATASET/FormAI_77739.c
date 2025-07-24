//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void divide(int x, int y)
{
    printf("%d / %d = ", x, y);
    if (y == 0) {
        printf("undefined\n");
        exit(EXIT_FAILURE);
    } else if (x < y) {
        printf("0\n");
    } else {
        int quotient = 1;
        while (y * quotient <= x) {
            quotient++;
        }
        quotient--;
        int remainder = x - y * quotient;
        printf("%d remainder %d\n", quotient, remainder);
        divide(y, remainder); // recursive call
    }
}

int main()
{
    int x, y;
    printf("Enter two integers (separated by a space): ");
    if (scanf("%d %d", &x, &y) != 2) {
        fprintf(stderr, "Error: Invalid input\n");
        return EXIT_FAILURE;
    }
    divide(x, y);

    return EXIT_SUCCESS;
}