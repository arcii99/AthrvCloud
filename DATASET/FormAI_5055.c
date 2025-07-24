//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototype for random conspiracy theory generator */
char* conspiracy_generator();

/* Main function */
int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate 10 random conspiracy theories */
    for(int i = 0; i < 10; i++) {
        printf("%s\n", conspiracy_generator());
    }

    /* Exit program */
    return 0;
}

/* Function to generate a random conspiracy theory */
char* conspiracy_generator() {
    /* List of conspiracy theories */
    char *theories[] = {
        "The government is hiding evidence of extraterrestrial life.",
        "The moon landing was faked by the government.",
        "Big Pharma is intentionally keeping effective treatments for diseases a secret.",
        "The world's elite are secretly controlling the global economy.",
        "Climate change is a hoax perpetuated for political gain.",
        "The Illuminati is real and is behind major world events.",
        "9/11 was an inside job orchestrated by the government.",
        "The world's major religions were created by a secret society for control.",
        "The cure for cancer exists but is being suppressed by the government.",
        "The world is controlled by shape-shifting lizard people."
    };

    /* Get the number of theories in the list */
    int num_theories = sizeof(theories) / sizeof(theories[0]);

    /* Choose a random theory to return */
    int random_index = rand() % num_theories;
    return theories[random_index];
}