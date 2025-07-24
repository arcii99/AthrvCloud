//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

int main(){
    int userAge, targetHeartRate, restingHeartRate, maximumHeartRate;
    float intensityLevel;
    char gender;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please answer the following questions:\n");

    printf("What is your age?\n");
    scanf("%d", &userAge);

    printf("What is your resting heart rate?\n");
    scanf("%d", &restingHeartRate);

    printf("What is your gender? (M/F)\n");
    scanf(" %c", &gender);

    // calculate maximum heart rate based on gender and age
    if (gender == 'M' || gender == 'm') {
        maximumHeartRate = 220 - userAge;
    } else if (gender == 'F' || gender == 'f') {
        maximumHeartRate = 226 - userAge;
    } else {
        printf("Invalid gender input.");
        return 0;
    }

    // calculate target heart rate zone
    targetHeartRate = ((maximumHeartRate - restingHeartRate) * intensityLevel) + restingHeartRate;

    // display results
    printf("\nYour maximum heart rate is: %d\n", maximumHeartRate);

    printf("\nIntensity Level Guide:\n");
    printf("1 - Low Intensity\n");
    printf("2 - Moderate Intensity\n");
    printf("3 - High Intensity\n");

    printf("\nWhat intensity level would you like to set as your target?\n");
    scanf("%f", &intensityLevel);

    printf("\nYour target heart rate range is %d-%d\n", restingHeartRate, targetHeartRate);

    return 0;
}