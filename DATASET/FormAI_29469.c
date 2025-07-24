//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

int fib(int n)
{
    if(n <= 1)
        return n;
    
    return fib(n-2) + fib(n-1);
}

int main()
{
    int num;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("The fibonacci series is:\n");

    for(int i=0; i<num; i++)
    {
        printf("%d ", fib(i));
    }

    return 0;
}