//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include<stdio.h>

//Function prototype
int factorial(int num);

int main()
{
    int n, result;
    printf("Enter a number: ");
    scanf("%d", &n);

    //Validation for negative number
    if(n < 0)
    {
        printf("Factorial of negative number is not possible\n");
    }
    else
    {
        result = factorial(n);
        printf("Factorial of %d = %d\n", n, result);
    }

    return 0;
}

//Recursive function to calculate factorial
int factorial(int num)
{
    if(num == 0) //Base case
    {
        return 1;
    }
    else //Recursive case
    {
        return num * factorial(num-1);
    }
}