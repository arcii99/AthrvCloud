//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int RecursiveCalculation(int x, int y, int z);

int main()
{
    int x, y, z, result;

    printf("Enter values for x, y and z: ");
    scanf("%d %d %d", &x, &y, &z);

    result = RecursiveCalculation(x, y, z);

    printf("The result is: %d", result);

    return 0;
}

int RecursiveCalculation(int x, int y, int z)
{
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return 1;
    }
    else if (x > 0 && y > 0 && z > 0 && x <= y && y <= z)
    {
        return RecursiveCalculation(x, y - 1, z) + RecursiveCalculation(x, y, z - 1) - RecursiveCalculation(x, y - 1, z - 1);
    }
    else
    {
        return RecursiveCalculation(x - 1, y, z) + RecursiveCalculation(x - 1, y - 1, z) + RecursiveCalculation(x - 1, y, z - 1) - RecursiveCalculation(x - 1, y - 1, z - 1);
    }
}