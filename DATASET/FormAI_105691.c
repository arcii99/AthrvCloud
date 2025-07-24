//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_planets = rand() % 1000 + 1; // generates a random number between 1 and 1000 for the number of planets

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("------------------------------------\n");
    printf("Number of planets in our galaxy: %d\n", num_planets);

    float prob = (float) num_planets * 0.0001; // calculates the probability of an alien invasion
    printf("Probability of an alien invasion: %.4f%%\n", prob);

    if (prob < 0.01) {
        printf("Low probability, don't worry too much.\n");
    } else if (prob < 0.05) {
        printf("Moderate probability, keep an eye on the skies.\n");
    } else if (prob < 0.1) {
        printf("High probability, stay alert!\n");
    } else {
        printf("Extreme probability, seek shelter immediately!\n");
    }

    return 0;
}