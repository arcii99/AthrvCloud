//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {FALSE, TRUE} bool;

/* Define our spaceship structure */
typedef struct spaceship {
    int hull_strength;
    int shield_strength;
    int laser_power;
} Spaceship;

/* Define our alien structure */
typedef struct alien {
    int health;
    int shield;
    int laser_power;
} Alien;

/* Function to generate a random integer between min and max (inclusive) */
int generate_random(int min, int max) {
    srand(time(NULL)); // Seed the random number generator with current time
    return (rand() % (max - min + 1)) + min;
}

/* Function to initialize our spaceship */
void initialize_spaceship(Spaceship *s) {
    s->hull_strength = 100;
    s->shield_strength = 75;
    s->laser_power = 50;
}

/* Function to initialize an alien */
void initialize_alien(Alien *a) {
    a->health = 100;
    a->shield = 50;
    a->laser_power = 30;
}

/* Function to simulate a space battle */
void space_battle(Spaceship *s, Alien *a) {
    printf("Welcome to the space battle!\n");
    printf("Your spaceship has:\nHull strength: %d\nShield strength: %d\nLaser power: %d\n", s->hull_strength, s->shield_strength, s->laser_power);
    printf("The enemy alien has:\nHealth: %d\nShield: %d\nLaser power: %d\n", a->health, a->shield, a->laser_power);

    /* Loop until either the spaceship or alien is destroyed */
    bool spaceship_destroyed = FALSE;
    bool alien_destroyed = FALSE;
    while (!spaceship_destroyed && !alien_destroyed) {
        /* Spaceship attacks alien */
        printf("Your spaceship attacks the alien!\n");
        int damage = generate_random(1, s->laser_power);
        if (damage < a->shield) {
            printf("The alien's shield absorbs the attack!\n");
            a->shield -= damage;
        } else {
            printf("The attack hits the alien!\n");
            a->health -= damage - a->shield;
            a->shield = 0;
        }
        if (a->health <= 0) {
            printf("The alien has been destroyed!\n");
            alien_destroyed = TRUE;
            break;
        }

        /* Alien attacks spaceship */
        printf("The alien returns fire!\n");
        int alien_damage = generate_random(1, a->laser_power);
        if (alien_damage < s->shield_strength) {
            printf("Your spaceship's shield absorbs the attack!\n");
            s->shield_strength -= alien_damage;
        } else {
            printf("Your spaceship has been hit!\n");
            s->hull_strength -= alien_damage - s->shield_strength;
            s->shield_strength = 0;
        }
        if (s->hull_strength <= 0) {
            printf("Your spaceship has been destroyed! Game over.\n");
            spaceship_destroyed = TRUE;
        }
    }
}

int main() {
    Spaceship my_ship;
    initialize_spaceship(&my_ship);

    Alien enemy;
    initialize_alien(&enemy);

    space_battle(&my_ship, &enemy);

    return 0;
}