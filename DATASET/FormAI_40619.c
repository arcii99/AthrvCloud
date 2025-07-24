//FormAI DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>

// Our main function
int main()
{
    // Declare and initialize our variables
    int userInput, count = 0, sum = 0, average = 0;

    // Request input from user
    printf("Enter an integer: ");

    // Read input from user
    scanf("%d", &userInput);

    // Loop to calculate the sum of all integers from 1 to userInput
    for (int i = 1; i <= userInput; i++)
    {
        // Add i to the sum
        sum += i;

        // Increment the count
        count++;
    }

    // Calculate the average
    average = sum / count;

    // Output the sum and average to the user
    printf("The sum of all integers from 1 to %d is: %d\n", userInput, sum);
    printf("The average of all integers from 1 to %d is: %d\n", userInput, average);

    // Return 0 to indicate program success
    return 0;
}