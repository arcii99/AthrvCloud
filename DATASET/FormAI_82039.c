//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

// Struct to store the probability of an alien invasion
typedef struct {
    bool is_imminent;
    float probability;
} alien_invasion_probability;

// Function to calculate the probability of an alien invasion
void calculate_alien_invasion_probability(float *probability, bool *is_imminent) 
{
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random number between 0 and 100
    int rand_num = rand_range(0, 100);
    
    // If the random number is less than 50, there is no alien invasion
    if (rand_num < 50) {
        *probability = 0.0;
        *is_imminent = false;
    } else {
        // Otherwise, there is a 50-50 chance of an imminent invasion
        *probability = rand_range(50, 100) / 100.0;
        *is_imminent = rand_range(0, 1);
    }
}

// Asynchronous function to calculate the alien invasion probability and print the result
void calculate_async(alien_invasion_probability *result) 
{
    float probability;
    bool is_imminent;
    
    // Calculate the alien invasion probability
    calculate_alien_invasion_probability(&probability, &is_imminent);
    
    // Store the result in the struct
    result->probability = probability;
    result->is_imminent = is_imminent;
    
    // Print the result
    printf("ALIEN INVASION PROBABILITY CALCULATED:\n");
    printf("Probability: %.2f%%\n", probability * 100);
    printf("Is imminent: %s\n", is_imminent ? "true" : "false");
}

int main() 
{
    // Initialize the result struct
    alien_invasion_probability result;
    
    // Call the asynchronous function to calculate the probability
    calculate_async(&result);
    
    // Wait for the calculation to finish
    printf("Calculating...\n");
    for (int i = 0; i < 5; i++) {
        printf("...\n");
        sleep(1);
    }
    
    // Print the final result
    printf("FINAL RESULT:\n");
    printf("Probability: %.2f%%\n", result.probability * 100);
    printf("Is imminent: %s\n", result.is_imminent ? "true" : "false");
    
    return 0;
}