//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>

int calorie_tracker(int days_left) {
    // base case: no more days left to track
    if (days_left == 0) {
        printf("You have reached the end of the tracking period.\n");
        return 0;
    }
    
    int calories_eaten, calories_burned, total_calories;
    
    // get input for calories eaten and burned
    printf("Enter the number of calories eaten today: ");
    scanf("%d", &calories_eaten);
    printf("Enter the number of calories burned today: ");
    scanf("%d", &calories_burned);
    
    // calculate remaining calories
    total_calories = total_calories + calories_eaten - calories_burned;
    printf("You have %d calories left for the day.\n", total_calories);
    
    // recursive call for next day
    return calorie_tracker(days_left - 1);
}

int main() {
    int num_days;
    
    printf("Welcome to the Fitness Tracker!\n");
    printf("How many days would you like to track? ");
    scanf("%d", &num_days);
    
    // start recursive function with initial number of days
    calorie_tracker(num_days);
    
    return 0;
}