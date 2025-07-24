//FormAI DATASET v1.0 Category: Scientific ; Style: mathematical
/* This program calculates the factorial of a given number using recursion */

#include<stdio.h>

// Function prototype
int calcFactorial(int num);

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check if the number is positive
    if(num < 0)
    {
        printf("Error: Factorial of a negative number is not defined.");
        return 0;
    }

    printf("%d! = %d", num, calcFactorial(num));
    return 0;
}

// Function to calculate factorial of a number
int calcFactorial(int num)
{
    if(num == 0 || num == 1)
        return 1;
    else
        return num * calcFactorial(num - 1);
}

/* Sample Output:
Enter a positive integer: 5
5! = 120
*/