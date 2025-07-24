//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate BMI
float calculateBMI(float weight, float height){
    return weight / (height*height);
}

// Struct for holding fitness data
typedef struct {
    float weight;
    float height;
    float bmi;
    int steps;
    int caloriesBurned;
} FitnessData;

// Function to update fitness data
void updateFitnessData(FitnessData* data, float weight, float height, int steps, int caloriesBurned){
    data->weight = weight;
    data->height = height;
    data->bmi = calculateBMI(weight, height);
    data->steps += steps;
    data->caloriesBurned += caloriesBurned;
}

int main(){
    srand(time(0)); // Seed the random number generator

    FitnessData data;
    data.weight = 70.0; // Set initial weight to 70 kg
    data.height = 1.75; // Set initial height to 1.75 m
    data.bmi = calculateBMI(data.weight, data.height);
    data.steps = 0;
    data.caloriesBurned = 0;

    // Simulate updating fitness data for a few days
    for(int i = 1; i <= 5; i++){
        float weightChange = (rand() % 5 + 1) / 10.0; // Random weight change between 0.1-0.5 kg
        float newWeight = data.weight + weightChange;
        float heightChange = (rand() % 5 + 1) / 100.0; // Random height change between 0.01-0.05 m
        float newHeight = data.height + heightChange;
        int steps = rand() % 5000 + 5000; // Random steps between 5000-9999
        int caloriesBurned = steps / 20; // Assume 1 step burns 0.05 calories

        updateFitnessData(&data, newWeight, newHeight, steps, caloriesBurned);

        printf("\nDay %d:\n", i);
        printf("Weight: %.1f kg\n", data.weight);
        printf("Height: %.2f m\n", data.height);
        printf("BMI: %.2f\n", data.bmi);
        printf("Steps: %d\n", data.steps);
        printf("Calories burned: %d\n", data.caloriesBurned);
    }

    return 0;
}