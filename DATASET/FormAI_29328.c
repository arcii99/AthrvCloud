//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

int fibRecursive(int x);

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The fibonacci sequence up to %d is: ", num);
    for(int i = 0; i <= num; i++)
    {
        printf("%d ", fibRecursive(i));
    }
    return 0;
}

int fibRecursive(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else
    {
        return (fibRecursive(x-1) + fibRecursive(x-2));
    }
}