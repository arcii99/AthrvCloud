//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caloriesBurned, steps;
    float distance, goalDistance;
    char option;

    printf("Welcome to Fitness Tracker\n");
    printf("Please enter the goal distance you want to achieve (in kms): ");
    scanf("%f", &goalDistance);

    printf("Initializing...Press enter to begin!\n");
    getchar();

    do
    {
        printf("Please enter the number of steps you took today: ");
        scanf("%d", &steps);

        distance = (float)steps/1312.34;  // Conversion of steps to distance covered in kilometers
        caloriesBurned = steps/20;  // Considering 20 steps burned 1 calorie

        printf("You covered %.2f kms and burned %d calories today.\n", distance, caloriesBurned);

        if(distance >= goalDistance)
        {
            printf("Congratulations! You have completed your goal distance for the day\n");
            break;
        }

        printf("Do you want to continue(y/n): ");
        scanf(" %c", &option);

    } while(option == 'y' || option == 'Y');

    printf("Good job! Keep up the good work.\n");

    return 0;
}