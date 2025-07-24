//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int caloriesConsumed = 0;
    int caloriesBurnt = 0;
    char option;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your calories consumed: ");
    scanf("%d", &caloriesConsumed);

    printf("Great, now enter your calories burnt: ");
    scanf("%d", &caloriesBurnt);

    int netCalories = caloriesConsumed - caloriesBurnt;
    printf("Your net calories for the day: %d\n", netCalories);

    if (netCalories > 0) {
        printf("Looks like you need to work out more. Want to do some pushups? (y/n)\n");
        scanf("%s", &option);
        if (option == 'y' || option == 'Y') {
            int pushupCount = rand() % 15 + 1;
            printf("Okay, do %d pushups now! Go, go, go!\n", pushupCount);
        } else {
            printf("Well, I guess it's okay to take a break. But don't forget to exercise tomorrow!\n");
        }
    } else if (netCalories < 0) {
        printf("Wow, you're on fire! You burnt off more than you consumed. Keep it up!\n");
    } else {
        printf("Right on track! Keep going!\n");
    }

    return 0;
}