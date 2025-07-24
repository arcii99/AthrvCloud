//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include<stdio.h>

void recursiveFunction(int x)
{
    if(x == 0)
    {
        printf("The value of x is %d\n", x);
        return;
    }

    printf("The value of x is %d\n", x);

    recursiveFunction(x-1);

    printf("The value of x is %d\n", x);
}

int main()
{
    int num = 10;

    recursiveFunction(num);

    return 0;
}