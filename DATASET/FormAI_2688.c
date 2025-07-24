//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>

int main()
{
    /* C Fitness Tracker */
    printf("Welcome to C Fitness Tracker!\n");
    printf("We'll help you keep track of your daily exercise and diet.\n");

    /* Variables for tracking exercise and diet */
    int minutes_exercise = 0;
    int calories_burned = 0;
    int calories_consumed = 0;
    int overall_calories = 0;

    /* Prompt user for exercise and diet information */
    printf("Enter amount of exercise in minutes: ");
    scanf("%d", &minutes_exercise);

    printf("Enter amount of calories burned during exercise: ");
    scanf("%d", &calories_burned);

    printf("Enter amount of calories consumed: ");
    scanf("%d", &calories_consumed);

    /* Calculate overall calorie intake */
    overall_calories = calories_consumed - calories_burned;

    /* Display results to user */
    printf("Exercise for %d minutes burned %d calories.\n", minutes_exercise, calories_burned);
    printf("You consumed %d calories.\n", calories_consumed);

    if (overall_calories > 0)
    {
        printf("Great job! You burned more calories than you consumed.\n");
    }
    else if (overall_calories < 0)
    {
        printf("Oops! You consumed more calories than you burned.\n");
    }
    else
    {
        printf("You consumed exactly the same amount of calories that you burned.\n");
    }

    return 0;
}