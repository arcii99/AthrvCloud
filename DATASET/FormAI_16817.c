//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>

int fibonacci(int n)
{
    if(n<=0) //base case
    {
        return 0; 
    }
    else if(n==1)
    {
        return 1; //base case
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2); //recursive call
    }
}

int main()
{
    int n=10;
    printf("The first %d Fibonacci numbers are:\n",n); //display message
    for(int i=0;i<n;i++)
    {
        printf("%d ",fibonacci(i)); //display Fibonacci number
    }

    return 0;
}