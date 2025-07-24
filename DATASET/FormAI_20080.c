//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20

// Structure to hold player information
typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int energy;
    int credits;
    int fuel;
} Player;

// Enum to represent different planets
typedef enum {
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE
} Planets;

// Function to play the space adventure game
void play_game(Player* player, Planets current_planet);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the player
    Player player;
    strcpy(player.name, "John Doe");
    player.health = 100;
    player.energy = 100;
    player.credits = 0;
    player.fuel = 100;
    
    // Send the player on a journey to different planets
    play_game(&player, EARTH);
    play_game(&player, MARS);
    play_game(&player, JUPITER);
    play_game(&player, SATURN);
    play_game(&player, URANUS);
    play_game(&player, NEPTUNE);
    
    printf("Congratulations, %s! You have completed your journey and have earned %d credits.\n", player.name, player.credits);
    
    return 0;
}

void play_game(Player* player, Planets current_planet) {
    printf("Welcome to planet %d!\n", current_planet);
    
    // Update player's fuel randomly
    int fuel_gain = rand() % 21 + 20;
    player->fuel += fuel_gain;
    printf("You have gained %d units of fuel. Your fuel level is now %d.\n", fuel_gain, player->fuel);
    
    // Update player's health randomly
    int health_loss = rand() % 21 + 10;
    player->health -= health_loss;
    printf("You have lost %d points of health. Your health level is now %d.\n", health_loss, player->health);
    if (player->health <= 0) {
        printf("Game over! You have run out of health.\n");
        exit(0);
    }

    // Random event
    int event_num = rand() % 5 + 1;
    switch (event_num) {
        case 1:
            printf("You have discovered a new species on this planet!\n");
            break;
        case 2:
            printf("You have found a valuable resource on this planet worth 50 credits!\n");
            player->credits += 50;
            break;
        case 3:
            printf("You have encountered hostile aliens on this planet.\n");
            int alien_damage = rand() % 21 + 10;
            player->health -= alien_damage;
            printf("The aliens attacked you and you lost %d points of health. Your health level is now %d.\n", alien_damage, player->health);
            if (player->health <= 0) {
                printf("Game over! You have been killed by hostile aliens.\n");
                exit(0);
            }
            break;
        case 4:
            printf("You have landed in a place with no breathable air.\n");
            int air_damage = rand() % 21 + 10;
            player->health -= air_damage;
            printf("You were exposed to the toxic air and you lost %d points of health. Your health level is now %d.\n", air_damage, player->health);
            if (player->health <= 0) {
                printf("Game over! You have suffocated due to lack of oxygen.\n");
                exit(0);
            }
            break;
        case 5:
            printf("You have made a new friend on this planet!\n");
            break;
    }

    // Update player's energy randomly
    int energy_loss = rand() % 21 + 10;
    player->energy -= energy_loss;
    printf("You have lost %d points of energy. Your energy level is now %d.\n", energy_loss, player->energy);
    if (player->energy <= 0) {
        printf("Game over! You have run out of energy.\n");
        exit(0);
    }

    // Ask player what they want to do
    printf("What would you like to do?\n");
    printf("1. Refuel\n");
    printf("2. Buy a health pack (10 credits for 10 points of health)\n");
    printf("3. Travel to a different planet (costs 50 fuel)\n");
    printf("4. Continue exploring this planet\n");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            int fuel_cost = (100 - player->fuel) / 2;
            if (player->credits < fuel_cost) {
                printf("You do not have enough credits to refuel.\n");
            } else {
                player->credits -= fuel_cost;
                player->fuel = 100;
                printf("You have refueled your ship. Your fuel level is now %d.\n", player->fuel);
            }
            break;
        }
        case 2: {
            if (player->credits < 10) {
                printf("You do not have enough credits to buy a health pack.\n");
            } else {
                player->credits -= 10;
                player->health += 10;
                printf("You have bought a health pack. Your health level is now %d.\n", player->health);
            }
            break;
        }
        case 3: {
            if (player->fuel < 50) {
                printf("You do not have enough fuel to travel to a different planet.\n");
            } else {
                player->fuel -= 50;
                printf("You have traveled to a different planet. Your fuel level is now %d.\n", player->fuel);
                int next_planet = current_planet + 1;
                play_game(player, next_planet);
            }
            break;
        }
        case 4: {
            play_game(player, current_planet);
            break;
        }
        default:
            printf("Invalid choice!\n");
            break;
    }
}