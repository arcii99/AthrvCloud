//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>

// Define the struct to hold user info and fitness data
struct User {
    char name[50];
    int age;
    int weight;
    int height;
    int caloriesBurned;
    int stepsTaken;
};

// Function to calculate calories burned based on steps taken
int calculateCaloriesBurned(int steps, int weight) {
    float caloriesPerStep = (float) weight * 0.04;
    int calories = (int) (steps * caloriesPerStep);
    return calories;
}

int main() {
    // Initialize the user struct
    struct User user = {"John", 25, 160, 70, 0, 0};

    // Ask user for input
    printf("Welcome, %s! Please enter the number of steps you've taken today: ", user.name);
    scanf("%d", &user.stepsTaken);

    // Calculate the calories burned based on steps taken
    user.caloriesBurned = calculateCaloriesBurned(user.stepsTaken, user.weight);

    // Output the results
    printf("\nName: %s\nAge: %d\nWeight: %d kg\nHeight: %d cm\nSteps taken: %d\nCalories burned: %d\n",
        user.name, user.age, user.weight, user.height, user.stepsTaken, user.caloriesBurned);

    return 0;
}