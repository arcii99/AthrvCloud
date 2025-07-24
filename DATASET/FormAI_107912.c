//FormAI DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

int recursiveFactorial(int num)
{
    if(num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * recursiveFactorial(num-1);
    }
}

int main()
{
    int num;
    printf("Enter a number to find the factorial: ");
    scanf("%d", &num);
    int result = recursiveFactorial(num);
    
    printf("The factorial of %d is %d", num, result);
    return 0;
}