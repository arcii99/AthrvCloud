//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding rand

    int spaceship_prob = rand() % 101; // random number from 0-100
    int army_prob = rand() % 101;
    int infiltration_prob = rand() % 101;
    int invasion_prob = (spaceship_prob + army_prob + infiltration_prob) / 3; // average of three probabilities

    // probability descriptions
    char *spaceship_desc, *army_desc, *infiltration_desc, *invasion_desc;

    if (spaceship_prob <= 25)
        spaceship_desc = "Highly unlikely";
    else if (spaceship_prob <= 50)
        spaceship_desc = "Somewhat possible";
    else if (spaceship_prob <= 75)
        spaceship_desc = "Likely";
    else
        spaceship_desc = "Almost certain";

    if (army_prob <= 25)
        army_desc = "Highly unlikely";
    else if (army_prob <= 50)
        army_desc = "Somewhat possible";
    else if (army_prob <= 75)
        army_desc = "Likely";
    else
        army_desc = "Almost certain";

    if (infiltration_prob <= 25)
        infiltration_desc = "Highly unlikely";
    else if (infiltration_prob <= 50)
        infiltration_desc = "Somewhat possible";
    else if (infiltration_prob <= 75)
        infiltration_desc = "Likely";
    else
        infiltration_desc = "Almost certain";

    if (invasion_prob <= 25)
        invasion_desc = "Highly unlikely";
    else if (invasion_prob <= 50)
        invasion_desc = "Somewhat possible";
    else if (invasion_prob <= 75)
        invasion_desc = "Likely";
    else
        invasion_desc = "Almost certain";

    // results
    printf("Spaceship probability: %d%% - %s\n", spaceship_prob, spaceship_desc);
    printf("Army probability: %d%% - %s\n", army_prob, army_desc);
    printf("Infiltration probability: %d%% - %s\n", infiltration_prob, infiltration_desc);
    printf("Invasion probability: %d%% - %s\n", invasion_prob, invasion_desc);

    return 0;
}