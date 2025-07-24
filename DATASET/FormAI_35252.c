//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include<stdio.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi = weight / (height * height);
    return bmi;
}

// Main function
int main() {
    float weight, height;
    int age;
    
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your weight in kg: ");
    scanf("%f", &weight);
    
    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    float bmi = calculateBMI(weight, height);
    printf("Your BMI: %0.2f\n", bmi);
    
    if(age >= 18) {
        if(bmi < 18.5) {
            printf("You are underweight.\n");
        } else if(bmi >= 18.5 && bmi <= 24.9) {
            printf("You are within a healthy weight range.\n");
        } else if(bmi >= 25 && bmi <= 29.9) {
            printf("You are overweight.\n");
        } else {
            printf("You are obese.\n");
        }
    } else {
        printf("Sorry, this application is only for adults.\n");
    }
    
    return 0;
}