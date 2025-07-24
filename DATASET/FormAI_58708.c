//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int probability = 0;
    int alien_distance, alien_size, alien_speed;
    srand(time(NULL));
    alien_distance = rand() % 100;
    alien_size = rand() % 10;
    alien_speed = rand() % 10;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please answer the following questions:\n");
    
    // Get user input
    int num_eyes, num_tentacles, num_antennas;
    printf("How many eyes do you have? ");
    scanf("%d", &num_eyes);
    printf("How many tentacles do you have? ");
    scanf("%d", &num_tentacles);
    printf("How many antennas do you have? ");
    scanf("%d", &num_antennas);
    
    // Calculate probability
    probability += num_eyes * 10;
    probability += num_tentacles * 5;
    probability += num_antennas * 3;
    
    // Adjust probability based on alien characteristics
    if (alien_distance <= 50)
        probability += 20;
    if (alien_size >= 5)
        probability += 10;
    if (alien_speed >= 5)
        probability += 5;
    
    // Output result
    printf("The probability of an alien invasion is %d%%\n", probability);
    
    return 0;
}