//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate maximum heart rate
int calculateMaxHeartRate(int age) {
    return 220 - age;
}

int main() {
    float weight, height, bmi;
    int age, maxHeartRate;

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your age in years: ");
    scanf("%d", &age);

    // Calculate BMI
    bmi = calculateBMI(weight, height);

    // Calculate maximum heart rate
    maxHeartRate = calculateMaxHeartRate(age);

    printf("\n--- Your Fitness Stats ---\n");
    printf("BMI: %0.2f\n", bmi);
    printf("Max Heart Rate: %d\n", maxHeartRate);

    // Output fitness level based on calculated values
    if (bmi < 18.5) {
        printf("Fitness Level: Underweight\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("Fitness Level: Normal Weight\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Fitness Level: Overweight\n");
    } else {
        printf("Fitness Level: Obese\n");
    }

    return 0;
}