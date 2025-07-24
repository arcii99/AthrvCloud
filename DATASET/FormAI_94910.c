//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include<stdio.h>

void main() {

    int calories_burned[7] = {250, 175, 300, 200, 275, 225, 250};
    float total_calories = 0, average_calories;
    int i;

    printf("********** C Fitness Tracker **********\n");
    printf("Calories burned this week:\n");

    for (i = 0; i < 7; i++) {
        printf("Day %d: %d\n", i+1, calories_burned[i]);
        total_calories += (float)calories_burned[i];
    }

    average_calories = total_calories / 7;
    printf("-------------------------------\n");
    printf("Total Calories Burned: %.2f\n", total_calories);
    printf("Average Calories Burned: %.2f\n", average_calories);
    
    if (average_calories > 250) {
        printf("Congratulations! You exceeded your target of burning 250 calories per day.\n");
    } else {
        printf("You need to work harder to achieve your target of burning 250 calories per day.\n");
    }
}