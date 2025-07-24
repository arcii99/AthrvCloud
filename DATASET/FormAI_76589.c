//FormAI DATASET v1.0 Category: Recursive ; Style: visionary
#include<stdio.h>
void fun(int n) 
{
    if (n == 1) //base condition
    {
        printf("1\n");
    }
    else if (n % 2 == 0) //condition for even numbers
    {
        printf("%d\n", n);
        fun(n/2);
    }
    else //condition for odd numbers
    {
        printf("%d\n", n);
        fun(3*n+1);
    }
}

int main() 
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num <= 0) //error handling for negative or zero input
    {
        printf("Invalid input. Please enter a positive integer\n");
    }
    else //if input is positive, call the function
    {
        fun(num);
    }
    return 0;
}