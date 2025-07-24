//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize the random seed
    int probability = rand() % 101; //generate a random probability between 0 and 100
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("------------------------------------\n");
    printf("Probability of alien invasion today: %d%%\n", probability);

    //determine the likelihood of an alien invasion based on the calculated probability
    if(probability <= 20) {
        printf("There is a low chance of an alien invasion today. Enjoy your day!\n");
    } else if(probability <= 50) {
        printf("There is a moderate chance of an alien invasion today. Stay alert and be prepared just in case.\n");
    } else if(probability <= 80) {
        printf("There is a high chance of an alien invasion today. Take necessary precautions and be ready to defend your planet!\n");
    } else {
        printf("There is an extremely high chance of an alien invasion today. This is not a drill. Evacuate immediately!\n");
    }

    return 0;
}