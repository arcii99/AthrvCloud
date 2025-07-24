//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include<stdio.h>

int fact(int num);

int main()
{
    int num, factorial;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    if(num < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
    }
    else
    {
        factorial = fact(num);
        printf("Factorial of %d = %d", num, factorial);
    }
    
    return 0;
}

int fact(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return(num * fact(num-1));
    }
}