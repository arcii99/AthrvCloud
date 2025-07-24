//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set the random seed based on current time

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");

    printf("Please enter the following information:\n");
    printf(" - Number of years since first contact: ");
    int years_since_contact;
    scanf("%d", &years_since_contact);

    printf(" - Number of known alien species: ");
    int num_species;
    scanf("%d", &num_species);

    printf(" - Average hostility rating (1-10) of known species: ");
    int alien_hostility;
    scanf("%d", &alien_hostility);

    printf("\nCalculating...\n\n");

    float base_probability = (float)years_since_contact / 1000.0;
    float hostility_multiplier = (float)alien_hostility / 10.0;
    float species_multiplier = (float)num_species / 5.0;

    float probability = base_probability * hostility_multiplier * species_multiplier;
    probability = probability > 1.0 ? 1.0 : probability; // limit probability to 1.0

    printf("RESULTS:\n");
    printf(" - Base probability: %.2f\n", base_probability);
    printf(" - Hostility multiplier: %.2f\n", hostility_multiplier);
    printf(" - Species multiplier: %.2f\n", species_multiplier);
    printf(" - Probability of alien invasion: %.2f%%\n", probability * 100.0);

    printf("\nBut wait, there's more!\n");
    int random_event = rand() % 100;
    if (random_event < 30) {
        printf(" - WARNING: Our sensors have detected unusual alien activity in our vicinity.\n");
    }
    else if (random_event < 60) {
        printf(" - ALERT: An alien vessel has been spotted in our solar system.\n");
    }
    else if (random_event < 90) {
        printf(" - UPDATE: We have made contact with a new alien species.\n");
    }
    else {
        printf(" - BREAKING NEWS: An alien invasion is happening RIGHT NOW!\n");
    }

    return 0;
}