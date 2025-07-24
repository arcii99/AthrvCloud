//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include<stdio.h>

/*This is a recursive function that calculates the factorial of a given number*/
int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int main()
{
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d",&num);
    if(num<0)
    {
        printf("Error! Factorial of negative number doesn't exist\n");
        return 0;
    }
    int result=factorial(num);
    printf("Factorial of %d is %d\n",num,result);
    return 0;
}