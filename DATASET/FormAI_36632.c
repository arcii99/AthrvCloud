//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// struct to hold fitness data
struct FitnessData {
    int steps;
    int calories_burned;
    float distance;
};

// function to calculate calories burned based on steps taken
int calculateCalories(int steps) {
    return steps / 20; // assuming 20 steps equals 1 calorie burned
}

int main() {
    struct FitnessData data; // creating instance of FitnessData struct
    
    // prompt user to enter their fitness data
    printf("Enter the number of steps taken: ");
    scanf("%d", &data.steps);
    printf("Enter the distance travelled (in km): ");
    scanf("%f", &data.distance);
    
    // calculate calories burned based on steps taken
    data.calories_burned = calculateCalories(data.steps);
    
    // display fitness data to the user
    printf("\nFitness Data:\n");
    printf("Steps taken: %d\n", data.steps);
    printf("Calories burned: %d\n", data.calories_burned);
    printf("Distance travelled: %.2f km\n", data.distance);
    
    return 0; // exit program
}