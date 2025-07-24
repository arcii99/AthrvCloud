//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>

int main() {
    float weight, height, bmi;

    // Prompt user for their weight and height
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);

    // Calculate the user's BMI
    bmi = weight / (height * height);

    // Display the user's BMI and a corresponding message
    printf("Your BMI is %0.2f.\n", bmi);
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi < 25) {
        printf("You are of normal weight.\n");
    } else if (bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    return 0;
}