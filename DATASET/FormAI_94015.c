//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>

int main() {
    float weight, height, bmi;

    // Prompt the user to input their weight and height
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);

    // Calculate the BMI
    bmi = weight / (height * height);

    // Display the results to the user
    printf("Your BMI is %.2f\n", bmi);

    return 0;
}