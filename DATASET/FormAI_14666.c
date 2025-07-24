//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLANETS 10

int main() {
    // initialize random number generator
    srand(time(NULL));
    
    // set up space adventure
    char* planets[MAX_PLANETS] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Alpha Centauri"};
    int num_planets = 6 + (rand() % 5); // choose between 6 to 10 planets
    printf("Welcome to the space adventure! You will explore %d planets.\n", num_planets);
    
    // travel through space
    for (int i = 0; i < num_planets; i++) {
        int planet_index = rand() % MAX_PLANETS;
        printf("Traveling to planet %s...\n", planets[planet_index]);
        
        // explore planet
        int alien_count = rand() % 10; // choose between 0 to 9 aliens
        if (alien_count > 0) {
            printf("You have encountered %d aliens on planet %s!\n", alien_count, planets[planet_index]);
            printf("Prepare for battle...\n");
            // simulate battle
            int player_health = 100;
            int alien_health = alien_count * 10;
            while (player_health > 0 && alien_health > 0) {
                int damage = rand() % 20; // choose between 0 to 19 damage
                player_health -= damage;
                printf("Alien attacks! You took %d damage. Your health is now %d.\n", damage, player_health);
                damage = rand() % 10; // choose between 0 to 9 damage
                alien_health -= damage;
                printf("You attack! You deal %d damage. Alien health is now %d.\n", damage, alien_health);
            }
            if (player_health <= 0) {
                printf("You have died.\n");
                break;
            } else {
                printf("You have defeated the aliens and gained valuable resources!\n");
            }
        } else {
            printf("You have explored the planet %s and found nothing of interest.\n", planets[planet_index]);
        }
    }
    
    // end space adventure
    printf("Congratulations, you have completed the space adventure!\n");
    return 0;
}