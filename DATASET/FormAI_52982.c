//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

float calculateBMI(float weight, float height) {
    float bmi = weight / (height * height);
    return bmi;
}

float calculateBMR(float weight, float height, int age, char gender) {
    float bmr;
    if (gender == 'M') {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    } else {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    }
    return bmr;
}

int main() {
    float weight, height;
    int age;
    char gender;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender (M or F): ");
    scanf(" %c", &gender);

    float bmi = calculateBMI(weight, height);
    float bmr = calculateBMR(weight, height, age, gender);

    printf("\nYour Body Mass Index (BMI) is %.2f\n", bmi);
    printf("Your Basal Metabolic Rate (BMR) is %.2f\n", bmr);

    return 0;
}