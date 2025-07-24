//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // set the seed of the random number generator to current time

    int num1 = rand() % 100; // generate a random number between 0 and 99
    int num2 = rand() % 100;

    int result1 = pow(num1, 2); // raise num1 to the power of 2
    int result2 = pow(num2, 3); // raise num2 to the power of 3

    int result3 = abs(num1 - num2); // get the absolute difference between num1 and num2
    int result4 = sqrt(result1 + result2); // get the square root of the sum of result1 and result2

    printf("Welcome to the C Math Exercise Program!\n\n");
    printf("Here are your two random numbers: %d %d\n\n", num1, num2);

    printf("Please select the operation you want to perform:\n\n");
    printf("1. Raise %d to power of 2\n", num1);
    printf("2. Raise %d to power of 3\n", num2);
    printf("3. Get the absolute difference between %d and %d\n", num1, num2);
    printf("4. Get the square root of the sum of %d^2 and %d^3\n\n", num1, num2);

    int choice = 0;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("%d^2 = %d\n", num1, result1);
            break;
        case 2:
            printf("%d^3 = %d\n", num2, result2);
            break;
        case 3:
            printf("Absolute difference between %d and %d is %d\n", num1, num2, result3);
            break;
        case 4:
            printf("Square root of %d^2 + %d^3 is %f\n", num1, num2, result4);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    printf("\nThank you for using C Math Exercise Program! Goodbye!");

    return 0;
}