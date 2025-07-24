//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>

// function to calculate BMI
float calculateBMI(float weight, float height){
    float bmi = weight / (height * height);
    return bmi;
}

// function to calculate calories burned during exercise
float calculateCaloriesBurned(float duration, float intensity, float weight){
    float calories = ((duration * intensity * 3.5 * weight) / 200);
    return calories;
}

int main(){
    float weight, height, duration, intensity;
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter the duration of your workout in minutes: ");
    scanf("%f", &duration);
    printf("Enter the intensity of your workout (1-10): ");
    scanf("%f", &intensity);

    float bmi = calculateBMI(weight, height);
    float caloriesBurned = calculateCaloriesBurned(duration, intensity, weight);

    printf("Your BMI is: %.2f\n", bmi);
    printf("You burned %.2f calories during your workout.", caloriesBurned);

    return 0;
}