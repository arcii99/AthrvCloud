//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

void recursiveFunction(int num)
{
    if(num<=0)
    {
        printf("We are done here!\n");
        return;
    }
    else
    {
        if(num%2 == 0)
        {
            printf("%d is an even number!\n",num);
        }
        else
        {
            printf("%d is an odd number!\n",num);
        }
        recursiveFunction(num-1);
    }
}

int main()
{
    int n;
    printf("Enter a positive integer to start the recursion:\n");
    scanf("%d", &n);
    printf("Starting the recursion from %d\n", n);
    recursiveFunction(n);
    printf("Recursion finished!\n");
    return 0;
}