//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
// Procedural Space Adventure Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int spaceship_health = 100;
int alien_ship_health = 100;

int main() {
    srand(time(NULL));
    printf("Welcome to the Procedural Space Adventure!\n\n");
    printf("Your spaceship has encountered an alien ship.\n");
    printf("You must battle it out to survive.\n\n");

    while (spaceship_health > 0 && alien_ship_health > 0) {
        int spaceship_attack_strength = rand() % 21 + 10;
        int alien_ship_attack_strength = rand() % 21 + 10;

        printf("Your spaceship attacks the alien ship and deals %d damage.\n", spaceship_attack_strength);
        alien_ship_health -= spaceship_attack_strength;
        if (alien_ship_health <= 0) {
            printf("Congratulations! Your spaceship has defeated the alien ship.\n");
            break;
        }

        printf("The alien ship retaliates and deals %d damage to your spaceship.\n", alien_ship_attack_strength);
        spaceship_health -= alien_ship_attack_strength;
        if (spaceship_health <= 0) {
            printf("Game Over! Your spaceship has been destroyed by the alien ship.\n");
            break;
        }

        printf("Your spaceship and the alien ship continue to battle it out.\n");
        printf("Spaceship health: %d\n", spaceship_health);
        printf("Alien ship health: %d\n\n", alien_ship_health);
    }

    return 0;
}