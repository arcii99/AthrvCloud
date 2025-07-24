//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num_species = rand()%5 + 1; // number of alien species
    double p_total = 0; // total probability
    int i;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We will use advanced mathematical formulas to calculate the probability of an alien invasion from %d different species.\n\n", num_species);

    // loop through each species
    for (i = 1; i <= num_species; i++) {
        double p_species = (double) rand()/RAND_MAX; // probability of invasion for this species
        printf("Alien Species #%d:\n", i);
        printf("Probability of Invasion: %.2lf\n", p_species);
        p_total += p_species; // add to total probability
        printf("\n");
    }

    // calculate and display final probability
    double p_final = p_total/num_species;
    printf("-------------------------------------------------\n");
    printf("FINAL PROBABILITY OF ALIEN INVASION: %.2lf\n", p_final);
    printf("-------------------------------------------------\n");

    return 0;
}