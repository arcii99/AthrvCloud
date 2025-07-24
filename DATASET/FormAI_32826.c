//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>

int main() {

    // Step 1: Define the variables
    float invasion_probability;
    int avg_distance;
    float detection_probability;

    // Step 2: Ask the user for input values
    printf("Enter the probability of alien invasion (0.0 - 1.0): ");
    scanf("%f", &invasion_probability);

    printf("Enter the average distance between earth and invading planet in million miles: ");
    scanf("%d", &avg_distance);

    printf("Enter the probability of detecting the aliens before the invasion (0.0 - 1.0): ");
    scanf("%f", &detection_probability);

    // Step 5: Implement error handling
    if(invasion_probability < 0.0 || invasion_probability > 1.0 || detection_probability < 0.0 || detection_probability > 1.0) {
        printf("Invalid input value(s)! Probability values must be between 0 and 1.\n");
        return 0;
    }

    if(avg_distance < 0) {
        printf("Invalid input value! Distance cannot be negative.\n");
        return 0;
    }

    // Step 3: Calculate the probability of invasion
    float inv_prob = (1.0 / avg_distance) * invasion_probability * (1.0 - detection_probability);

    // Step 4: Display the results to the user
    printf("The probability of alien invasion is %.2f%%\n", inv_prob * 100);

    return 0;
}