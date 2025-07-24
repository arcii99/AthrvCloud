//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>

int main() {
    int age, height_inches, weight_lbs;
    float bmr;
    char gender;

    printf("Welcome to the Fitness Tracker!\n");

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your height (in inches): ");
    scanf("%d", &height_inches);

    printf("Please enter your weight (in pounds): ");
    scanf("%d", &weight_lbs);

    printf("Please enter your gender (m/f): ");
    scanf(" %c", &gender);

    if (gender == 'm') {
        bmr = 66 + (6.3 * weight_lbs) + (12.9 * height_inches) - (6.8 * age);
    } else if (gender == 'f') {
        bmr = 655 + (4.3 * weight_lbs) + (4.7 * height_inches) - (4.7 * age);
    } else {
        printf("Invalid gender entered.\n");
        return 1;
    }

    printf("\nYour Basal Metabolic Rate (BMR) is %.2f calories per day.\n", bmr);

    return 0;
}