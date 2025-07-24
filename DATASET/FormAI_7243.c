//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

int generateFibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return generateFibonacci(n-1) + generateFibonacci(n-2);
}

void drawSquare(int n, int x, int y)
{
    if (n == 1)
    {
        printf("(%d, %d) -> ", x, y);
        printf("(%d, %d)\n", x+1, y);
        printf("(%d, %d) -> ", x+1, y);
        printf("(%d, %d)\n", x+1, y+1);
        printf("(%d, %d) -> ", x+1, y+1);
        printf("(%d, %d)\n", x, y+1);
        printf("(%d, %d) -> ", x, y+1);
        printf("(%d, %d)\n", x, y);
        return;
    }

    drawSquare(n-1, x, y);
    drawSquare(n-1, x+(1<<(n-2)), y);
    drawSquare(n-1, x, y+(1<<(n-2)));
    drawSquare(n-1, x+(1<<(n-2)), y+(1<<(n-2)));
}

int main()
{
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", generateFibonacci(i));
    printf("\n\n");

    printf("Recursive squares (level 3):\n");
    drawSquare(3, 0, 0);
    return 0;
}