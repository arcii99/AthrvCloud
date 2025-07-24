//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Define variables
    int total_minutes, calories_burned;
    float miles_walked, mph;

    // Input data
    printf("Enter total minutes of exercise: ");
    scanf("%d", &total_minutes);
    printf("Enter total number of calories burned: ");
    scanf("%d", &calories_burned);
    printf("Enter total miles walked: ");
    scanf("%f", &miles_walked);

    // Calculate average speed in miles per hour
    mph = miles_walked / (total_minutes / 60.0);

    // Display results
    printf("\n********************************************\n");
    printf("Total time of exercise: %d minutes\n", total_minutes);
    printf("Total number of calories burned: %d\n", calories_burned);
    printf("Total miles walked: %.2f\n", miles_walked);
    printf("Average speed: %.2f mph\n", mph);
    printf("********************************************\n");

    // Analyze data and suggest improvements
    if (calories_burned < 100) {
        printf("\n*** You need to burn more calories! Try more intense workouts. ***\n");
    } else if (calories_burned < 500) {
        printf("\n*** Good job on burning calories! Try increasing workout time or intensity. ***\n");
    } else {
        printf("\n*** Excellent job on burning calories! Keep up the great work! ***\n");
    }
    if (mph < 2.0) {
        printf("\n*** Your walking speed is slow. Try walking longer distances or increasing your pace. ***\n");
    } else if (mph < 4.0) {
        printf("\n*** Your walking speed is good. Try walking for longer durations. ***\n");
    } else {
        printf("\n*** Your walking speed is excellent! Keep walking! ***\n");
    }

    return 0;
}