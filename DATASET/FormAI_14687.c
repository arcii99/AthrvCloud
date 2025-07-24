//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>

// Define a struct to hold fitness data for a user
typedef struct {
    float weight;
    float height;
    int age;
    int steps;
    float calories;
} FitnessData;

int main() {
    // Create an instance of the FitnessData struct
    FitnessData user = {75.0, 1.8, 28, 0, 0.0};
    
    // Prompt the user to input their weight, height, and age
    printf("Welcome to the Fitness Tracker! Let's get started.\n");
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &user.weight);
    printf("Please enter your height in meters: ");
    scanf("%f", &user.height);
    printf("Please enter your age in years: ");
    scanf("%d", &user.age);
    
    // Loop to simulate tracking fitness data throughout the day
    for (int i = 0; i < 10; i++) {
        // Prompt the user to input how many steps they have taken
        printf("\n\nHow many steps have you taken so far today? ");
        scanf("%d", &user.steps);
        
        // Calculate the amount of calories burned based on steps taken and user data
        user.calories = 0.035 * user.weight * user.steps;
        
        // Display the user's fitness data for the day
        printf("\n\n***** FITNESS DATA FOR DAY %d *****\n", i+1);
        printf("Weight: %.1f kg\n", user.weight);
        printf("Height: %.1f m\n", user.height);
        printf("Age: %d years\n", user.age);
        printf("Steps: %d\n", user.steps);
        printf("Calories burned: %.2f\n", user.calories);
    }
    
    // Thank the user for using the Fitness Tracker
    printf("\n\nThank you for using the Fitness Tracker!\n");
    
    // Return 0 to indicate successful program execution
    return 0;
}