//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets;
    int num_invaded = 0;
    int num_attempts = 1000000; // Change this to increase/decrease precision
    float invasion_prob;

    srand(time(NULL));

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    if (num_planets <= 0) {
        printf("Invalid number of planets!\n");
        return 1;
    }

    printf("Simulating %d invasion attempts...\n", num_attempts);

    for (int i = 0; i < num_attempts; i++) {
        int invaders = rand() % 1000 + 1;
        int defenders = rand() % 1000 + 1;

        if (invaders > defenders) {
            num_invaded++;
        }
    }

    invasion_prob = (float) num_invaded / (float) num_attempts;

    printf("Invasion probability for a planet with %d defenders: %.2f%%\n", num_planets, invasion_prob * 100);

    return 0;
}