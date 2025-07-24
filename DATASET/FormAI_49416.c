//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int weight, height, num_days;
    double calories;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to C Fitness Tracker!\n");
    printf("Please enter your weight in pounds: ");
    scanf("%d", &weight);
    printf("Please enter your height in inches: ");
    scanf("%d", &height);
    printf("Please enter the number of days you want to track: ");
    scanf("%d", &num_days);

    printf("\nDay\tCalories Burned\n");

    for (int i = 1; i <= num_days; i++) {
        double randFactor = (double)(rand() % 40) / 100.0 + 0.8; // random factor between 0.8 and 1.2
        calories = (0.57 * weight + 0.41 * height) * randFactor;
        printf("%d\t%.2f\n", i, calories);
    }

    return 0;
}