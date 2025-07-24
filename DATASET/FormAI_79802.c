//FormAI DATASET v1.0 Category: Recursive ; Style: Alan Touring
#include <stdio.h>

int fibonacci(int num)
{
    if(num == 0)
    {
        return 0;
    }
    else if(num == 1)
    {
        return 1;
    }
    else
    {
        return (fibonacci(num-1) + fibonacci(num-2));
    }
}

int main()
{
    int num, i;
    printf("Enter the number of terms in the series: \n");
    scanf("%d",&num);
    printf("Fibonacci series: ");
    for(i=0; i<num; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}