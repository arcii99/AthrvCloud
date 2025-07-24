//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int alienProbability = rand() % 101; // Random number between 0 and 100 inclusive

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Today's probability of an alien invasion is %d%%\n", alienProbability);

    if (alienProbability < 10) {
        printf("Phew! No need to worry about an alien invasion today.\n");
    } else if (alienProbability >= 10 && alienProbability < 50) {
        printf("Better keep an eye on the skies, there's a moderate chance of an alien invasion today.\n");
    } else if (alienProbability >= 50 && alienProbability < 90) {
        printf("Uh oh, there's a high probability of an alien invasion today. Time to get your tin foil hats ready.\n");
    } else {
        printf("ALIEN INVASION IMMINENT. ABANDON ALL HOPE AND PREPARE FOR THE WORST.\n");
    }

    return 0;
}