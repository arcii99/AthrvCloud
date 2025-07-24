//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_of_aliens = rand() % 100;
    int probability_of_invasion = 0;

    printf("Alien Invasion Probability Calculator\n");

    if (num_of_aliens >= 70) {
        probability_of_invasion = rand() % 80 + 20;
        printf("Warning! Large presence of aliens detected. Probability of invasion: %d%%\n", probability_of_invasion);
    } else if (num_of_aliens >= 30) {
        probability_of_invasion = rand() % 60 + 10;
        printf("Attention! Moderate presence of aliens detected. Probability of invasion: %d%%\n", probability_of_invasion);
    } else {
        probability_of_invasion = rand() % 30;
        printf("No significant presence of alien activity detected. Probability of invasion: %d%%\n", probability_of_invasion);
    }

    printf("Please enter the number of troops stationed in the area: ");
    int num_of_troops = 0;
    scanf("%d", &num_of_troops);

    if (num_of_troops >= 10000) {
        probability_of_invasion -= 20;
        printf("High troop presence detected. Probability of invasion lowered to %d%%\n", probability_of_invasion);
    } else if (num_of_troops >= 5000) {
        probability_of_invasion -= 10;
        printf("Moderate troop presence detected. Probability of invasion lowered to %d%%\n", probability_of_invasion);
    } else {
        probability_of_invasion += 10;
        printf("Low troop presence detected. Probability of invasion increased to %d%%\n", probability_of_invasion);
    }

    if (probability_of_invasion > 50) {
        printf("Evacuate the area immediately!\n");
    } else {
        printf("Remain on high alert and prepare for possible invasion.\n");
    }

    return 0;
}