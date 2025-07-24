//FormAI DATASET v1.0 Category: Scientific ; Style: mathematical
#include <stdio.h>

int calcFactorial(int num); //function to calculate factorial

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    //check if input is positive
    if (n < 0)
    {
        printf("Error: Entered number is negative. Exiting...\n");
        return 0;
    }
    else if (n == 0)
    {
        printf("Factorial of 0 is 1");
        return 0;
    }

    int sum = 0; //variable to store sum of factorials
    for (int i = 1; i <= n; i++)
    {
        int fact = calcFactorial(i);
        sum += fact;
    }

    printf("\nSum of factorials of first %d integers is %d\n", n, sum);

    return 0;
}

int calcFactorial(int num)
{
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}