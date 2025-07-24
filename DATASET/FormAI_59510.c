//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include<stdio.h>
#include<string.h>

int main(){

    char name[50];
    int age;
    float weight, height, bmi;
    int steps;
    float calories;

    printf("Welcome to the Fitness Tracker Program!\n");
    printf("Please enter your name:");
    scanf("%s", name);
    printf("Hi %s! Please enter your age: ", name);
    scanf("%d", &age);
    printf("Enter your weight in Kg: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    printf("\n**********\n");
    printf("Name: %s \n", name);
    printf("Age: %d \n", age);
    printf("Weight: %.2f Kg\n", weight);
    printf("Height: %.2f meters\n", height);
    printf("BMI: %.2f\n", bmi);
    printf("**********\n\n");

    printf("Let's track your fitness activity for today!\n");
    printf("Enter the number of steps you have taken: ");
    scanf("%d", &steps);

    // assume 50 steps burn 1 calorie
    calories = steps / 50.0;

    printf("Great job! You have taken %d steps and burned %.2f calories\n", steps, calories);

    return 0;
}