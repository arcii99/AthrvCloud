//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int day, month, year;
    float weight;
    char choice;

    printf("Welcome to the Fitness Tracker!\n\n");

    printf("Please enter today's date (day/month/year): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Please enter your weight today (in kg): ");
    scanf("%f", &weight);

    printf("Date: %d/%d/%d\n", day, month, year);
    printf("Weight: %.2f kg\n", weight);

    printf("\nWould you like to log your exercise? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        printf("\nWhat type of exercise did you do? ");
        char exercise[20];
        scanf("%s", exercise);

        printf("How long did you exercise (in minutes)? ");
        int duration;
        scanf("%d", &duration);

        printf("\nExercise logged!\n");
        printf("Type: %s\n", exercise);
        printf("Duration: %d minutes\n", duration);
    }

    printf("\nThank you for using the Fitness Tracker!\n");

    return 0;
}