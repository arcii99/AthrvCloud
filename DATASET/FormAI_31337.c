//FormAI DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random number generator
    srand(time(NULL));

    // Generate two random integers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    // Display the problem
    printf("What is the sum of %d and %d?\n", num1, num2);

    // Get the user's answer
    int response;
    scanf("%d", &response);

    // Check the answer and provide feedback
    if (response == num1 + num2)
    {
        printf("Congratulations! You got it right!\n");
    }
    else
    {
        printf("Sorry, that's not correct. The correct answer is %d.\n", num1 + num2);
    }

    return 0;
}