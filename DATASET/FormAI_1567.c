//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

int recursiveFactorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * recursiveFactorial(num - 1);
    }
}

int main()
{
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d.\n", num, recursiveFactorial(num));
    return 0;
}