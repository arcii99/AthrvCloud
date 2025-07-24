//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>

// Define the struct that will hold all our fitness data
struct fitness_data {
    int steps;
    double distance;
    double calories_burned;
};

// Function to update the fitness data
void update_fitness_data(struct fitness_data* data, int steps_taken) {
    // Update the number of steps
    data->steps += steps_taken;

    // Calculate the distance
    data->distance = data->steps * 0.5;

    // Calculate the calories burned
    data->calories_burned = data->steps * 0.05;
}

// Function to print the fitness data
void print_fitness_data(struct fitness_data data) {
    printf("Steps Taken: %d\n", data.steps);
    printf("Distance Travelled: %f km\n", data.distance);
    printf("Calories Burned: %f kcal\n", data.calories_burned);
}

int main() {
    // Initialize our fitness_data struct
    struct fitness_data data = {0, 0.0, 0.0};

    // Prompt the user to input the number of steps taken
    printf("Enter the number of steps taken: ");
    int steps_taken = 0;
    scanf("%d", &steps_taken);

    // Update the fitness data
    update_fitness_data(&data, steps_taken);

    // Print the updated fitness data
    print_fitness_data(data);

    return 0;
}