//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    float weight, height, bmi, calories;
    int age;

    // Taking user input
    printf("Enter your weight in kg: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your age in years: ");
    scanf("%d", &age);

    // Calculating BMI
    bmi = weight / (height * height);
    printf("Your BMI is: %.2f\n", bmi);

    // Calculating calories
    calories = 10 * weight + 6.25 * height * 100 - 5 * age + 5;
    printf("Your daily calorie intake should be: %.2f calories\n", calories);

    return 0;
}