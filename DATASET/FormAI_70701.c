//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int invasionProbability = 0;
    int i;
    
    // Initializes the random seed
    srand((unsigned) time(NULL));
    
    // Generates a random number between 0 and 100
    invasionProbability = rand() % 101;
    
    printf("********** ALIEN INVASION PROBABILITY CALCULATOR **********\n");
    printf("Calculations based on latest intelligence data.\n");
    printf("Invasion probability is: %d%%\n\n", invasionProbability);
    
    // Determine the level of risk
    if(invasionProbability < 30) {
        printf("The risk level is LOW, the probability of an alien invasion is low.\n");
    } else if(invasionProbability> 30 && invasionProbability < 70) {
        printf("The risk level is MEDIUM, the probability of an alien invasion is moderate.\n");
    } else {
        printf("The risk level is HIGH, the probability of an alien invasion is high.\n\n");
        
        // Output the time until invasion
        printf("Time until invasion: \n");
        for(i = 10; i > 0; i--) {
            printf("%d...\n", i);
            sleep(1);
        }
        printf("\n\nALIEN INVASION DETECTED!!! TAKE COVER IMMEDIATELY!!!\n");
    }
    
    return 0;
}