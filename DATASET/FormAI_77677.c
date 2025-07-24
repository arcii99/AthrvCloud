//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to generate a random number within a specific range
int random_range(int min_val, int max_val) {
    // seed the random number generator
    srand(time(NULL));
    // generate random number within range
    return (rand() % (max_val - min_val + 1)) + min_val;
}

// function to simulate a battle between the spaceship and an alien spacecraft
bool simulate_battle(int alien_strength) {
    int player_strength = random_range(50, 100);
    if (player_strength > alien_strength) {
        printf("You defeated the alien spacecraft!\n");
        return true;
    } else {
        printf("The alien spacecraft was too powerful, you have been defeated.\n");
        return false;
    }
}

int main() {
    int spaceship_health = 100;
    int planet_distance = 50000;
    int alien_count = 0;

    printf("Welcome to the Space Adventure game!\n");
    printf("You are the captain of a spaceship traveling through the galaxy.\n");

    // loop until the spaceship reaches the planet
    while (planet_distance > 0) {
        printf("\nCurrent Distance to Planet: %d km\n", planet_distance);

        // randomly encounter an alien spacecraft during the journey
        int encounter_chance = random_range(1, 10);
        if (encounter_chance <= 3) {
            printf("You have encountered an alien spacecraft!\n");
            bool battle_won = simulate_battle(random_range(30, 80));
            if (battle_won) {
                alien_count++;
            } else {
                spaceship_health -= 20;
                if (spaceship_health <= 0) {
                    printf("Your spaceship was destroyed, game over!\n");
                    return 0;
                }
            }
        }

        // move the spaceship forward
        int distance_traveled = random_range(1000, 5000);
        planet_distance -= distance_traveled;
        printf("You have traveled %d km closer to your destination.\n", distance_traveled);

        // replenish the spaceship's health
        if (alien_count >= 5) {
            spaceship_health += 20;
            printf("You have found a repair kit and restored your spaceship's health!\n");
        }
    }

    printf("\nCongratulations! You have successfully reached the planet!\n");
    printf("You encountered %d alien spacecraft on your journey.\n", alien_count);
    printf("Your spaceship's health is %d.\n", spaceship_health);

    return 0;
}