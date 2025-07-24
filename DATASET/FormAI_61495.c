//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to Procedural Space Adventure!\n");

    // Set random seed
    srand(time(NULL));

    // Generate a random planet
    int planet_num = rand() % 10;
    char *planet_name = "";
    switch(planet_num) {
        case 0: planet_name = "Mediterra"; break;
        case 1: planet_name = "Adrastea"; break;
        case 2: planet_name = "Eurydome"; break;
        case 3: planet_name = "Antheia"; break;
        case 4: planet_name = "Helike"; break;
        case 5: planet_name = "Tethys"; break;
        case 6: planet_name = "Kalyke"; break;
        case 7: planet_name = "Hyperion"; break;
        case 8: planet_name = "Iapetus"; break;
        case 9: planet_name = "Atlas"; break;
    }

    printf("You are now on the planet of %s!\n", planet_name);

    // Generate alien encounter probability
    int alien_prob = rand() % 3;
    if(alien_prob == 0) {
        printf("You have encountered alien life forms! They seem hostile...\n");

        // Generate alien strength
        int alien_strength = rand() % 11;
        printf("The aliens have a strength of %d out of 10.\n", alien_strength);

        // Generate player strength
        int player_strength = rand() % 11;
        printf("You have a strength of %d out of 10.\n", player_strength);

        // Determine outcome of fight
        if(player_strength >= alien_strength) {
            printf("You have defeated the aliens!\n");
        } else {
            printf("You were defeated by the aliens. Game over.\n");
            return 0;
        }
    } else {
        printf("No alien encounters on this planet. You're safe... for now.\n");
    }

    // Generate spaceship malfunction probability
    int spaceship_prob = rand() % 3;
    if(spaceship_prob == 0) {
        printf("Your spaceship is malfunctioning! You need to find a way to repair it.\n");

        // Generate repair item probability
        int repair_prob = rand() % 3;
        if(repair_prob == 0) {
            printf("You have found a repair kit and have successfully repaired your spaceship!\n");
        } else {
            printf("You were unable to find a repair kit and are now stranded on the planet. Game over.\n");
            return 0;
        }
    } else {
        printf("Your spaceship is functioning normally. Time to explore the planet!\n");
    }

    // Generate resource encounter probability
    int resource_prob = rand() % 3;
    if(resource_prob == 0) {
        printf("You have found valuable resources on this planet!\n");

        // Generate resource type
        int resource_type = rand() % 3;
        switch(resource_type) {
            case 0: printf("You have found a cache of precious metals.\n"); break;
            case 1: printf("You have discovered a rare plant that has medicinal properties.\n"); break;
            case 2: printf("You have stumbled upon a rich vein of crystal minerals.\n"); break;
        }
    } else {
        printf("No valuable resources found on this planet. Time to move on.\n");
    }

    printf("Congratulations, you have successfully completed your space adventure on %s!\n", planet_name);

    return 0;
}