//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function to calculate the user's age */
int calculate_age(int year, int month, int day) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    int current_year = local->tm_year + 1900;
    int current_month = local->tm_mon + 1;
    int current_day = local->tm_mday;

    int age = current_year - year;
    if (current_month < month || (current_month == month && current_day < day))
        age--;
    return age;
}

int main() {
    char name[20];
    int gender;
    int year, month, day;
    float height, weight;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your gender (0 for male, 1 for female): ");
    scanf("%d", &gender);

    printf("Please enter your birthdate in the format YYYY-MM-DD: ");
    scanf("%d-%d-%d", &year, &month, &day);

    /* Call the function to calculate the user's age */
    int age = calculate_age(year, month, day);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    /* Calculate BMI */
    float bmi = weight / (height * height);

    printf("\nName: %s\n", name);
    printf("Gender: %s\n", gender == 0 ? "Male" : "Female");
    printf("Age: %d\n", age);
    printf("Height: %.2fm\n", height);
    printf("Weight: %.2fkg\n", weight);
    printf("BMI: %.2f\n", bmi);
    printf("Fitness Level: ");

    /* Calculate fitness level based on age and BMI */
    if (age >= 18 && age <= 24) {
        if (gender == 0 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 0 && bmi >= 18.5 && bmi <= 24.9)
            printf("Normal");
        else if (gender == 0 && bmi >= 25 && bmi <= 29.9)
            printf("Overweight");
        else if (gender == 0 && bmi >= 30)
            printf("Obese");
        else if (gender == 1 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 1 && bmi >= 18.5 && bmi <= 22.9)
            printf("Normal");
        else if (gender == 1 && bmi >= 23 && bmi <= 27.4)
            printf("Overweight");
        else if (gender == 1 && bmi >= 27.5)
            printf("Obese");
    }
    else if (age >= 25 && age <= 34) {
        if (gender == 0 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 0 && bmi >= 18.5 && bmi <= 25.9)
            printf("Normal");
        else if (gender == 0 && bmi >= 26 && bmi <= 29.9)
            printf("Overweight");
        else if (gender == 0 && bmi >= 30)
            printf("Obese");
        else if (gender == 1 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 1 && bmi >= 18.5 && bmi <= 23.9)
            printf("Normal");
        else if (gender == 1 && bmi >= 24 && bmi <= 28.4)
            printf("Overweight");
        else if (gender == 1 && bmi >= 28.5)
            printf("Obese");
    }
    else if (age >= 35 && age <= 44) {
        if (gender == 0 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 0 && bmi >= 18.5 && bmi <= 26.9)
            printf("Normal");
        else if (gender == 0 && bmi >= 27 && bmi <= 30.9)
            printf("Overweight");
        else if (gender == 0 && bmi >= 31)
            printf("Obese");
        else if (gender == 1 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 1 && bmi >= 18.5 && bmi <= 24.9)
            printf("Normal");
        else if (gender == 1 && bmi >= 25 && bmi <= 29.9)
            printf("Overweight");
        else if (gender == 1 && bmi >= 30)
            printf("Obese");
    }
    else if (age >= 45 && age <= 54) {
        if (gender == 0 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 0 && bmi >= 18.5 && bmi <= 27.4)
            printf("Normal");
        else if (gender == 0 && bmi >= 27.5 && bmi <= 30.9)
            printf("Overweight");
        else if (gender == 0 && bmi >= 31)
            printf("Obese");
        else if (gender == 1 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 1 && bmi >= 18.5 && bmi <= 26.9)
            printf("Normal");
        else if (gender == 1 && bmi >= 27 && bmi <= 30.9)
            printf("Overweight");
        else if (gender == 1 && bmi >= 31)
            printf("Obese");
    }
    else if (age >= 55 && age <= 64) {
        if (gender == 0 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 0 && bmi >= 18.5 && bmi <= 28.4)
            printf("Normal");
        else if (gender == 0 && bmi >= 28.5 && bmi <= 31.9)
            printf("Overweight");
        else if (gender == 0 && bmi >= 32)
            printf("Obese");
        else if (gender == 1 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 1 && bmi >= 18.5 && bmi <= 27.4)
            printf("Normal");
        else if (gender == 1 && bmi >= 27.5 && bmi <= 31.4)
            printf("Overweight");
        else if (gender == 1 && bmi >= 31.5)
            printf("Obese");
    }
    else if (age >= 65) {
        if (gender == 0 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 0 && bmi >= 18.5 && bmi <= 29.4)
            printf("Normal");
        else if (gender == 0 && bmi >= 29.5 && bmi <= 31.9)
            printf("Overweight");
        else if (gender == 0 && bmi >= 32)
            printf("Obese");
        else if (gender == 1 && bmi < 18.5)
            printf("Underweight");
        else if (gender == 1 && bmi >= 18.5 && bmi <= 30.9)
            printf("Normal");
        else if (gender == 1 && bmi >= 31 && bmi <= 34.9)
            printf("Overweight");
        else if (gender == 1 && bmi >= 35)
            printf("Obese");
    }

    printf("\n\nThank you for using the C Fitness Tracker!");
    return 0;
}