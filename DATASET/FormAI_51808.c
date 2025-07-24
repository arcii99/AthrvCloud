//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to check if user has entered a valid number
bool isValidNumber(float number) {
    if (number < 0.0f || number > 1000.0f) {
        printf("Invalid input. Please enter a number between 0 and 1000.\n");
        return false;
    }
    return true;
}

// function to calculate body mass index (BMI)
float calculateBMI(float weight, float height) {
    float bmi = (weight / (height * height)) * 703;
    return bmi;
}

int main() {
    float weight, height;
    bool isValidWeight = false;
    bool isValidHeight = false;
    bool hasEnteredData = false;

    // paranoia about user input
    while (!isValidWeight || !isValidHeight || !hasEnteredData) {
        printf("Please enter your weight in pounds: ");
        scanf("%f", &weight);
        isValidWeight = isValidNumber(weight);

        printf("Please enter your height in inches: ");
        scanf("%f", &height);
        isValidHeight = isValidNumber(height);

        if (isValidWeight && isValidHeight) {
            float bmi = calculateBMI(weight, height);
            printf("Your BMI is: %.2f\n", bmi);
            hasEnteredData = true;
        } else {
            printf("Please try again.\n");
        }
    }
    return 0;
}