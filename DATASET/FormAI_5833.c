//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 1, nextNum, n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
            nextNum = i;
        else
        {
            nextNum = num1 + num2;
            num1 = num2;
            num2 = nextNum;
        }
        printf("%d ", nextNum);
    }

    return 0;
}