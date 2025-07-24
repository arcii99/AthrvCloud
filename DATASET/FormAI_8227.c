//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int calories_burned, exercise_time, heart_rate, steps;
    double distance_covered;

    // User Inputs
    printf("Enter the exercise time (minutes): ");
    scanf("%d", &exercise_time);

    printf("Enter the heart rate (bpm): ");
    scanf("%d", &heart_rate);

    printf("Enter the number of steps taken: ");
    scanf("%d", &steps);

    // Calculations
    calories_burned = 4 * (exercise_time / 60) * heart_rate;
    distance_covered = steps * 0.0005;

    // Outputs
    printf("\nYOU HAVE BURNED %d CALORIES\n", calories_burned);
    printf("YOU HAVE COVERED %.2lf km\n", distance_covered);

    return 0;
}