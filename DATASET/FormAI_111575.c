//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

void recursiveFunction(int num);

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    recursiveFunction(number);

    return 0;
}

void recursiveFunction(int num)
{
    if(num == 0)
    {
        printf("You have reached the end of recursion!\n");
    }
    else
    {
        printf("You are currently in recursion level %d\n", num);
        recursiveFunction(num-1);
    }
}