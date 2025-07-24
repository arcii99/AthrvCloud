//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fitness Tracker example program
int main() {
    //Variable declaration
    float weight, height, bmi;
    int steps, calories, hours_exercised;
    char name[20];

    printf("Welcome to Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hi %s, let's get started!\n", name);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    bmi = weight / pow(height, 2);
    printf("Your Body Mass Index (BMI) is: %.2f\n", bmi);

    printf("Please enter the number of steps you have taken today: ");
    scanf("%d", &steps);

    calories = steps * 0.05;
    printf("You have burnt %d calories.\n", calories);

    printf("Please enter the number of hours you have exercised today: ");
    scanf("%d", &hours_exercised);

    calories += hours_exercised * 250;
    printf("You have burnt a total of %d calories today!\n", calories);

    printf("Thank you for using Fitness Tracker!\n");

    return 0;
}