//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

int recursive_function(int n);

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("The sum of integers from 1 to %d is %d\n", num, recursive_function(num));

    return 0;
}

int recursive_function(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + recursive_function(n-1);
    }
}