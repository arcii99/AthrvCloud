//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>

int main()
{
    int calories_burned, steps_walked, total_calories = 0, total_steps = 0;
    float distance_walked;
    char response;

    printf("Welcome to the C Fitness Tracker!\n");

    do {
        printf("\nEnter the number of calories burned today: ");
        scanf("%d", &calories_burned);
        printf("Enter the number of steps you walked today: ");
        scanf("%d", &steps_walked);

        distance_walked = steps_walked * 0.0008;
        printf("You walked %.2f kilometers today.\n", distance_walked);

        total_calories += calories_burned;
        total_steps += steps_walked;

        printf("Do you want to enter more data? (y or n): ");
        scanf(" %c", &response);
    } while (response == 'y');

    printf("\nTotal calories burned: %d\n", total_calories);
    printf("Total steps walked: %d\n", total_steps);
    printf("Total distance walked: %.2f kilometers\n", total_steps * 0.0008);

    return 0;
}