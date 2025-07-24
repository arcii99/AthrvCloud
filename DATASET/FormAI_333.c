//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>

int main() {
    int age, weight, height;
    float bmi;

    printf("Enter your age (in years): ");
    scanf("%d", &age);

    printf("Enter your weight (in kg): ");
    scanf("%d", &weight);

    printf("Enter your height (in cm): ");
    scanf("%d", &height);

    bmi = (float) weight / ((float) height / 100.0 * (float) height / 100.0);

    printf("Your BMI is: %f\n", bmi);

    if (age < 18) {
        printf("This tracker is only recommended for use by adults.\n");
    } else if (bmi < 18.5) {
        printf("Your BMI is underweight. You should aim to gain weight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("Your BMI is healthy. Maintain your current weight and exercise regularly.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Your BMI is overweight. You should aim to lose weight.\n");
    } else {
        printf("Your BMI is obese. You should make significant lifestyle changes to improve your health.\n");
    }

    return 0;
}