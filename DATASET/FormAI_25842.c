//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between a range of values
int generate_random(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate a space battle between the spaceship and an alien ship
void space_battle(int spaceship_attack, int alien_attack) {
    int spaceship_hp = 100;
    int alien_hp = 100;

    printf("The spaceship has %d HP and the alien ship has %d HP!\n", spaceship_hp, alien_hp);

    // Attack until one of the ships' HP reaches 0
    while (spaceship_hp > 0 && alien_hp > 0) {
        // Spaceship attacks first
        alien_hp -= spaceship_attack;
        printf("Spaceship deals %d damage! Alien ship has %d HP remaining!\n", spaceship_attack, alien_hp);

        // If alien is destroyed before it attacks
        if (alien_hp <= 0) {
            printf("Spaceship destroys the alien ship!\n");
            return;
        }

        // Alien attacks next
        spaceship_hp -= alien_attack;
        printf("Alien ship deals %d damage! Spaceship has %d HP remaining!\n", alien_attack, spaceship_hp);

        // If spaceship is destroyed before it attacks
        if (spaceship_hp <= 0) {
            printf("Alien ship destroys the spaceship!\n");
            return;
        }
    }
}

int main() {
    printf("Welcome to the C Procedural Space Adventure!\n");

    // Generate a random number between 1 and 3 to determine the spaceship's weapon
    int spaceship_weapon = generate_random(1, 3);
    printf("Your spaceship's weapon: ");

    switch (spaceship_weapon) {
        case 1:
            printf("Photon blaster\n");
            break;
        case 2:
            printf("Plasma cannon\n");
            break;
        case 3:
            printf("Ion blaster\n");
            break;
    }

    // Generate a random number between 1 and 3 to determine the alien ship's weapon
    int alien_weapon = generate_random(1, 3);
    printf("Alien ship's weapon: ");

    switch (alien_weapon) {
        case 1:
            printf("Laser gun\n");
            break;
        case 2:
            printf("Particle beam\n");
            break;
        case 3:
            printf("Plasma cannon\n");
            break;
    }

    // Generate a random number between 75 and 125 to determine spaceship's attack power
    int spaceship_attack = generate_random(75, 125);

    // Generate a random number between 75 and 125 to determine alien ship's attack power
    int alien_attack = generate_random(75, 125);

    printf("Let the space battle begin!\n");
    space_battle(spaceship_attack, alien_attack);

    return 0;
}