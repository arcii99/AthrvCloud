//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>

//function to calculate body mass index
float calcBMI(float weight, float height) {
    float bmi = weight / (height * height);
    return bmi;
}

int main() {
    float weight, height, bmi;

    printf("Welcome to SmartFit Fitness Tracker!\n");
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    bmi = calcBMI(weight, height);

    printf("\nYour Body Mass Index (BMI) is %.2f\n", bmi);

    //evaluate BMI
    if (bmi < 18.5) {
        printf("You are underweight, please consult with a nutritionist.\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("You are in a healthy weight range, keep it up!\n");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight, try to incorporate more exercise into your routine and consult with a nutritionist.\n");
    } else {
        printf("You are considered obese, please consult with a health professional immediately.\n");
    }

    return 0;
}