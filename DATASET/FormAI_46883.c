//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <math.h>

/* Function to calculate the nth power of a number */
double nthPower(double num, int n)
{
    return pow(num, n);
}

int main()
{
    int numA, numB, numC;
    double result1, result2, result3;

    /* Ask user to input three integer numbers */
    printf("Enter three integer numbers: ");
    scanf("%d%d%d", &numA, &numB, &numC);

    printf("\n");

    /* Calculate the square of the first number */
    result1 = nthPower(numA, 2);
    printf("The square of %d is: %.2lf\n", numA, result1);

    /* Calculate the cube of the second number */
    result2 = nthPower(numB, 3);
    printf("The cube of %d is: %.2lf\n", numB, result2);

    /* Calculate the fourth power of the third number */
    result3 = nthPower(numC, 4);
    printf("The fourth power of %d is: %.2lf\n", numC, result3);

    /* Calculate the sum of all results */
    double sumResults = result1 + result2 + result3;

    printf("\n");

    /* Print the sum along with a message */
    printf("The sum of the results is: %.2lf\n", sumResults);

    return 0;
}