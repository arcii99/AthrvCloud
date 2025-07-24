//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>

void recursiveFunction(int n);

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    recursiveFunction(num);
    return 0;
}

void recursiveFunction(int n)
{
    if(n <= 0)
    {
        printf("%d is not a positive integer, please enter a positive integer.\n", n);
        int newNum;
        scanf("%d", &newNum);
        recursiveFunction(newNum);
    }
    else if(n == 1)
    {
        printf("1\n");
    }
    else
    {
        recursiveFunction(n-1);
        printf("%d\n", n);
    }
}