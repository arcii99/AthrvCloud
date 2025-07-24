//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdio.h>

int factorial(int n)
{
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
}

void main()
{
    int num, sum=0, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    for(i=0;i<=num;i++)
    {
        sum+=factorial(i);
    }
    printf("The sum of factorials from 0 to %d is: %d", num, sum);
}