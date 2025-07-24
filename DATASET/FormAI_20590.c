//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>

int main() {

    float weight;
    int minutes;
    float caloriesBurned;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("---------------------------------\n");

    printf("Please enter your weight in pounds: ");
    scanf("%f", &weight);

    printf("Please enter the number of minutes of your workout: ");
    scanf("%d", &minutes);

    caloriesBurned = (weight * 0.75) * (float) minutes / 60.0;

    printf("\n");

    printf("Results:\n");
    printf("Your weight: %.2f pounds\n", weight);
    printf("Minutes of workout: %d\n", minutes);
    printf("Calories burned: %.2f\n", caloriesBurned);

    return 0;
}