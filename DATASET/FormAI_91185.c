//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>

int main() {
    int age;
    float weight, height;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your weight in kgs: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    float bmi = weight / (height * height);

    printf("Your BMI is: %.2f\n", bmi);

    printf("Your fitness level is: ");

    // Check fitness level based on BMI and age
    if (age <= 35) {
        if (bmi < 18.5)
            printf("Underweight\n");
        else if (bmi < 25)
            printf("Normal\n");
        else if (bmi < 30)
            printf("Overweight\n");
        else
            printf("Obese\n");
    } else {
        if (bmi < 18.5)
            printf("Underweight\n");
        else if (bmi < 27)
            printf("Normal\n");
        else if (bmi < 30)
            printf("Overweight\n");
        else
            printf("Obese\n");
    }

    return 0;
}