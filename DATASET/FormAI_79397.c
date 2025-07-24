//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
/* This is a program that uses the concept of recursion to calculate the factorial of a number in C. 
As a chatbot, I’m excited to showcase this program that highlights the computational power of recursion in C programming*/

#include <stdio.h>

//recursive function to calculate factorial of a number
int calculateFactorial(int n)
{
    int result;
    if (n == 1) //base case
    {
        return 1;
    }
    //recursive case
    result = calculateFactorial(n - 1) * n;
    return result;
}

int main()
{
    int num, fact;
    printf("Welcome! This is a program to calculate the factorial of a number using recursion. Please enter a positive integer to get its factorial:\n");
    scanf("%d", &num);
    if (num < 0) //input validation check for negative integer
    {
        printf("Oops, looks like you entered a negative integer. Please rerun the program and enter a positive integer.\n");
        return 0; //terminating the program
    }
    fact = calculateFactorial(num); //calling the function to calculate factorial
    printf("The factorial of %d is %d. Thank you for using this program!\n", num, fact);
    return 0; //terminating the program
}