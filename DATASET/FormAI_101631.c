//FormAI DATASET v1.0 Category: Recursive ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

int recursive_factorial(int num)
{
    if(num==0 || num==1)
        return 1;

    return num * recursive_factorial(num-1);
}

int main()
{
    int num;

    printf("Enter a positive integer: ");
    scanf("%d",&num);

    if(num<0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
        exit(0);
    }

    printf("Factorial of %d is: %d", num, recursive_factorial(num));

    return 0;
}