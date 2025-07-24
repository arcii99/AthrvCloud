//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables for user input
    float weight;
    int age;
    int minutesOfExercise;

    // Get user input
    printf("Enter your weight in pounds: ");
    scanf("%f", &weight);
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("Enter the number of minutes you exercised today: ");
    scanf("%d", &minutesOfExercise);

    // Calculate calories burned
    float caloriesBurned;
    caloriesBurned = ((age * 0.074) - (weight * 0.05741) + (minutesOfExercise * 0.4472) - 20.4022) * 4.184;

    // Print daily fitness report
    printf("\n");
    printf("*********************************************\n");
    printf("            DAILY FITNESS REPORT              \n");
    printf("*********************************************\n");
    printf("Weight: %.2f pounds\n", weight);
    printf("Age: %d years\n", age);
    printf("Minutes of Exercise: %d\n", minutesOfExercise);
    printf("Calories Burned: %.2f\n", caloriesBurned);
    printf("\n");

    // Determine level of fitness
    printf("Based on your daily fitness report, you are ");
    if (caloriesBurned < 200) {
        printf("sedentary.\n");
    } else if (caloriesBurned < 500) {
        printf("moderately active.\n");
    } else {
        printf("highly active.\n");
    }

    return 0;
}