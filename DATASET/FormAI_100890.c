//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>

int main() {
    int age, height, weight;
    float bmi;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your height in cm: ");
    scanf("%d", &height);
    printf("Enter your weight in kg: ");
    scanf("%d", &weight);
    bmi = weight/((height/100.0)*(height/100.0));
    printf("Your BMI is: %.2f\n", bmi);
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("You are healthy.\n");
    }
    else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight.\n");
    }
    else {
        printf("You are obese.\n");
    }
    return 0;
}