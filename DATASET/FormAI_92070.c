//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int multivariableFactorial(int x, int y)
{
    if (x == 0 && y == 0)
      return 1;
    else if (x == y)
      return x * multivariableFactorial(x-1, y-1);
    else if (x > y)
      return x * multivariableFactorial(x-1, y);
    else
      return y * multivariableFactorial(x, y-1);
}

int main()
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Multivariable factorial of %d and %d is %d", x, y, multivariableFactorial(x, y));
    return 0;
}