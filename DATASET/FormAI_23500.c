//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
//Here is an Ada Lovelace style unique C Syntax parsing example program.

#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);

    if(a > b)
    {
        printf("%d is greater than %d",a,b);
    }
    else if(b > a)
    {
        printf("%d is greater than %d",b,a);
    }
    else
    {
        printf("%d and %d are equal",a,b);
    }

    return 0;
}

/*
In this program, we have taken two integers as input from the user using scanf() function.
We have then compared the two numbers using if-else statements and printed which one is greater.
If both numbers are equal, then we print that they are equal.
*/