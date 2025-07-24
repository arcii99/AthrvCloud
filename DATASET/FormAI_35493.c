//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL));
    int star_intensity = rand() % 100; // generate star intensity randomly between 0 and 100
    int planet_distance = rand() % 100; // generate planet distance randomly between 0 and 100
    float alien_intelligence = (float)(rand() % 1000) / 1000; // generate alien intelligence randomly between 0 and 1
    float inv_prob = ((star_intensity / 100.0) * (planet_distance / 100.0) * (alien_intelligence)); // calculate invasion probability
    printf("Star Intensity: %d\n", star_intensity);
    printf("Planet Distance: %d\n", planet_distance);
    printf("Alien Intelligence: %f\n", alien_intelligence);
    printf("Invasion Probability: %f\n", inv_prob);
    return 0;
}