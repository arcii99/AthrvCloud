//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

/* This is a program to calculate the factorial of any integer number using recursion */

int factorial(int num);

int main()
{
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Sorry, factorial of negative numbers does not exist.");
    } else {
        printf("Factorial of %d is %d", num, factorial(num));
    }
    return 0;
}

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

/*
Sample Input: 5

Sample Output: Factorial of 5 is 120
*/