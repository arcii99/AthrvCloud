//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>

// Functions to calculate BMI and fitness level
float calculateBMI(float height, float weight) {
    return weight / (height * height);
}

int calculateFitnessLevel(int minutesOfExercise, int heartRate) {
    if (minutesOfExercise >= 30 && heartRate >= 120) {
        return 3;
    } else if (minutesOfExercise >= 20 && heartRate >= 100) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    float height;
    float weight;
    int minutesOfExercise;
    int heartRate;
    int fitnessLevel;

    // Accept user inputs
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Enter number of minutes of exercise today: ");
    scanf("%d", &minutesOfExercise);
    printf("Enter your current heart rate: ");
    scanf("%d", &heartRate);

    // Calculate BMI and fitness level
    float bmi = calculateBMI(height, weight);
    fitnessLevel = calculateFitnessLevel(minutesOfExercise, heartRate);

    // Display results
    printf("\nYour BMI is %.2f", bmi);
    printf("\nYour fitness level is %d", fitnessLevel);

    // Check if user needs to improve fitness level
    if (fitnessLevel < 3) {
        printf("\nYou need to improve your fitness level!");
    }

    return 0;
}