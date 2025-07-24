//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num_of_planets;
    int invasion_probability = 0;
    int successful_invasions = 0;
    int total_invasions = 0;
    float success_rate;
    srand((unsigned int)time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many planets would you like to calculate for? ");
    scanf("%d", &num_of_planets);

    // Calculate invasion probability for each planet
    for(int i = 0; i < num_of_planets; i++) {
        printf("Calculating invasion probability for planet %d...\n", i+1);
        // Randomly generate a probability value between 0 and 100
        invasion_probability = rand() % 101;
        printf("Invasion probability: %d%%\n", invasion_probability);

        // Simulate invasion attempts based on probability value
        if(invasion_probability >= 50) {
            printf("Alien invasion successful!\n");
            successful_invasions++;
        }
        else {
            printf("Alien invasion failed!\n");
        }
        total_invasions++;
    }

    // Calculate success rate and output results
    success_rate = (float)successful_invasions / total_invasions * 100;
    printf("\nTotal number of planets invaded: %d\n", total_invasions);
    printf("Number of successful invasions: %d\n", successful_invasions);
    printf("Success rate: %.2f%%\n", success_rate);

    return 0;
}