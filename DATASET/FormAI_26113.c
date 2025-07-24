//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include<stdio.h>

// This is a recursive function
int factorial(int n)
{
    if(n == 1) // Base case
    {
        return 1;
    }
    else // Recursive case
    {
        return n * factorial(n-1);
    }
}

int main()
{
    int num;
    printf("Welcome to the Factorial Calculator!\n");
    printf("Please enter a positive integer: ");

    scanf("%d",&num);

    if(num<0)
    {
      printf("Error: Please enter a positive integer.");
      return 0;
    }

    int result = factorial(num); //Calling recursive function
    
    printf("\nFactorial of %d is: %d\n", num, result);
    printf("Thank you for using the Factorial Calculator!");
    return 0;
}