//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>

int main()

{
    int days, steps, calories, total_steps = 0, total_calories = 0;

    printf("Enter number of days: ");
    scanf("%d", &days);

    for(int i = 1; i <= days; i++)
    {
        printf("\nDay %d\n", i);

        printf("Enter number of steps for the day: ");
        scanf("%d", &steps);

        printf("Enter number of calories burnt: ");
        scanf("%d", &calories);

        total_steps += steps;
        total_calories += calories;
    }

    printf("\nTotal number of steps taken: %d", total_steps);
    printf("\nTotal number of calories burnt: %d", total_calories);

    printf("\nAverage number of steps taken per day: %d", total_steps/days);
    printf("\nAverage number of calories burnt per day: %d", total_calories/days);

    return 0;
}