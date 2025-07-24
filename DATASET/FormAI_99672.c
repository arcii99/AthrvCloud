//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initialise random seed

    int num_planets, invasion_probability;

    printf("Enter the number of planets to calculate the invasion probability: ");
    scanf("%d", &num_planets);

    printf("\n=== Alien Invasion Probability Calculator ===\n");
    printf("Calculating invasion probability for %d planets...\n\n", num_planets);

    // Calculate invasion probability for each planet
    for(int i=1; i<=num_planets; i++) {

        invasion_probability = rand() % 101; // Generate a random number from 0 to 100
        printf("Planet %d: Invasion Probability = %d%%\n", i, invasion_probability);

        if(invasion_probability > 50) { // If invasion probability is greater than 50%
            printf("WARNING: HIGH RISK OF ALIEN INVASION ON PLANET %d!\n\n", i);
        }
        else {
            printf("No immediate threat detected.\n\n");
        }
    }

   return 0;
}