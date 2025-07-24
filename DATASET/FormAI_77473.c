//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>

int main(void) {
    int num_planets, num_civilizations, invasion_prob;
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);
    printf("Enter the estimated number of civilizations in the galaxy: ");
    scanf("%d", &num_civilizations);
    if (num_planets < 1 || num_civilizations < 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    invasion_prob = ((double) num_civilizations / num_planets) * 100;
    printf("The probability of an alien invasion is %d%%.\n", invasion_prob);
    return 0;
}