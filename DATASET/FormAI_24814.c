//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>

int main() {
    int days_completed;
    double weight, height, average_steps, average_calories;
    
    printf("Welcome to C Fitness Tracker!\n");
    printf("Please enter the number of days you have completed: ");
    scanf("%d", &days_completed);
    
    printf("Please enter your weight (in pounds): ");
    scanf("%lf", &weight);
    
    printf("Please enter your height (in inches): ");
    scanf("%lf", &height);
    
    double bmi = weight / (height * height) * 703;
    printf("Your BMI is: %.2lf\n", bmi);
    
    printf("Please enter your average daily steps: ");
    scanf("%lf", &average_steps);
    
    printf("Please enter your average daily calories burned: ");
    scanf("%lf", &average_calories);
    
    double total_steps = average_steps * days_completed;
    printf("Total steps taken in %d days: %.0lf\n", days_completed, total_steps);
    
    double total_calories = average_calories * days_completed;
    printf("Total calories burned in %d days: %.0lf\n", days_completed, total_calories);
    
    printf("\nThe C Fitness Tracker summary:\n");
    printf("--------------------------------\n");
    printf("  Days completed: %d\n", days_completed);
    printf("  Weight: %.1lf lbs\n", weight);
    printf("  Height: %.1lf inches\n", height);
    printf("  BMI: %.1lf\n", bmi);
    printf("  Average daily steps: %.0lf\n", average_steps);
    printf("  Average daily calories burned: %.0lf\n", average_calories);
    printf("  Total steps taken: %.0lf\n", total_steps);
    printf("  Total calories burned: %.0lf\n", total_calories);
    
    return 0;
}