//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age, weight, height, activity_level, calories_needed;
    char gender;
    
    printf("Welcome to the Fitness Tracker!\n");
    
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    printf("Please enter your weight in pounds: ");
    scanf("%d", &weight);
    
    printf("Please enter your height in inches: ");
    scanf("%d", &height);
    
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);
    
    printf("Please select your activity level:\n");
    printf("1. Sedentary (little or no exercise)\n");
    printf("2. Lightly active (exercise or sports 1-3 days a week)\n");
    printf("3. Moderately active (exercise or sports 3-5 days a week)\n");
    printf("4. Very active (hard exercise or sports 6-7 days a week)\n");
    printf("5. Super active (very hard exercise or sports, physical job or training twice a day)\n");
    scanf("%d", &activity_level);
    
    switch(gender)
    {
        case 'M':
            calories_needed = (66 + (6.3 * weight) + (12.9 * height) - (6.8 * age)) * activity_level;
            break;
        
        case 'F':
            calories_needed = (655 + (4.3 * weight) + (4.7 * height) - (4.7 * age)) * activity_level;
            break;
            
        default:
            printf("Invalid input. Please enter M or F.\n");
            return 0;
    }
    
    printf("You need approximately %d calories per day to maintain your current weight.\n", calories_needed);
    
    return 0;
}