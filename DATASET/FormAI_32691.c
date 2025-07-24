//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>

int main() {

    // Declare variables
    float weight, pushups, situps, running, totalCalories;

    // Prompt user for weight
    printf("Please enter your weight in pounds: ");
    scanf("%f", &weight);

    // Prompt user for number of push-ups completed
    printf("How many push-ups did you complete today? ");
    scanf("%f", &pushups);

    // Prompt user for number of sit-ups completed
    printf("How many sit-ups did you complete today? ");
    scanf("%f", &situps);

    // Prompt user for running time in minutes
    printf("How many minutes did you run today? ");
    scanf("%f", &running);

    // Calculate total calories burned using MET values and weight
    float pushupMETs = 3.5;
    float situpMETs = 2.0;
    float runningMETs = 10;
    float pushupCalories = pushupMETs * weight * (pushups / 60);
    float situpCalories = situpMETs * weight * (situps / 60);
    float runningCalories = runningMETs * weight * (running / 60);
    totalCalories = pushupCalories + situpCalories + runningCalories;

    // Print out the total calories burned
    printf("Congratulations on a job well done, you burned %.2f calories today!\n", totalCalories);

    return 0;
}