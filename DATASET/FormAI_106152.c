//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_PLANETS 10
#define MAX_CHARACTERS 10

// struct definition for planet
typedef struct Planet {
    char name[20];
    char description[50];
    int distance;
    int resources;
} Planet;

// struct definition for enemy
typedef struct Enemy {
    char name[20];
    char description[50];
    int health;
    int attack;
} Enemy;

// struct definition for character
typedef struct Character {
    char name[20];
    char description[50];
    int health;
    int attack;
    int resources;
} Character;

// function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // initialize random number generator
    srand(time(NULL));

    // arrays to hold planets, enemies, and characters
    Planet planets[MAX_PLANETS];
    Enemy enemies[MAX_ENEMIES];
    Character characters[MAX_CHARACTERS];

    // populate planets array
    strcpy(planets[0].name, "Earth");
    strcpy(planets[0].description, "The planet you call home");
    planets[0].distance = 0;
    planets[0].resources = 100;

    strcpy(planets[1].name, "Mars");
    strcpy(planets[1].description, "The red planet");
    planets[1].distance = random_number(10, 20);
    planets[1].resources = random_number(50, 100);

    strcpy(planets[2].name, "Jupiter");
    strcpy(planets[2].description, "The biggest planet in the solar system");
    planets[2].distance = random_number(30, 40);
    planets[2].resources = random_number(100, 150);

    strcpy(planets[3].name, "Saturn");
    strcpy(planets[3].description, "The planet with the rings");
    planets[3].distance = random_number(50, 60);
    planets[3].resources = random_number(150, 200);

    strcpy(planets[4].name, "Uranus");
    strcpy(planets[4].description, "The sideways planet");
    planets[4].distance = random_number(70, 80);
    planets[4].resources = random_number(200, 250);

    strcpy(planets[5].name, "Neptune");
    strcpy(planets[5].description, "The planet with the great dark spot");
    planets[5].distance = random_number(90, 100);
    planets[5].resources = random_number(250, 300);

    strcpy(planets[6].name, "Pluto");
    strcpy(planets[6].description, "The dwarf planet");
    planets[6].distance = random_number(110, 120);
    planets[6].resources = random_number(300, 350);

    // populate enemies array
    strcpy(enemies[0].name, "Alien");
    strcpy(enemies[0].description, "A strange creature from another planet");
    enemies[0].health = random_number(10, 20);
    enemies[0].attack = random_number(5, 10);

    strcpy(enemies[1].name, "Robot");
    strcpy(enemies[1].description, "A machine designed for destruction");
    enemies[1].health = random_number(20, 30);
    enemies[1].attack = random_number(10, 15);

    strcpy(enemies[2].name, "Zombie");
    strcpy(enemies[2].description, "A creature risen from the dead");
    enemies[2].health = random_number(30, 40);
    enemies[2].attack = random_number(15, 20);

    strcpy(enemies[3].name, "Dragon");
    strcpy(enemies[3].description, "A fire-breathing beast from legend");
    enemies[3].health = random_number(40, 50);
    enemies[3].attack = random_number(20, 25);

    strcpy(enemies[4].name, "Kaiju");
    strcpy(enemies[4].description, "A giant monster from the depths of the ocean");
    enemies[4].health = random_number(50, 60);
    enemies[4].attack = random_number(25, 30);

    // populate characters array
    strcpy(characters[0].name, "Captain");
    strcpy(characters[0].description, "The fearless leader of the crew");
    characters[0].health = 100;
    characters[0].attack = random_number(10, 20);
    characters[0].resources = 0;

    strcpy(characters[1].name, "Navigator");
    strcpy(characters[1].description, "The expert at finding the way");
    characters[1].health = 100;
    characters[1].attack = random_number(5, 10);
    characters[1].resources = 0;

    strcpy(characters[2].name, "Engineer");
    strcpy(characters[2].description, "The master of the ship's systems");
    characters[2].health = 100;
    characters[2].attack = random_number(5, 10);
    characters[2].resources = 0;

    // game loop
    int game_over = 0;
    int current_planet = 0;
    while (!game_over) {
        // print current planet information
        printf("Welcome to %s!\n\n", planets[current_planet].name);
        printf("%s\n", planets[current_planet].description);
        printf("Distance from Earth: %d million miles\n", planets[current_planet].distance);
        printf("Resources available: %d\n\n", planets[current_planet].resources);

        // print character information
        printf("Your crew:\n");
        for (int i = 0; i < MAX_CHARACTERS; i++) {
            printf("%s - %s (Health: %d, Attack: %d, Resources: %d)\n", characters[i].name, characters[i].description, characters[i].health, characters[i].attack, characters[i].resources);
        }
        printf("\n");

        // randomly encounter an enemy
        if (random_number(0, 1) == 1) {
            int enemy_index = random_number(0, MAX_ENEMIES - 1);
            printf("You have encountered a %s!\n", enemies[enemy_index].name);
            printf("%s\n\n", enemies[enemy_index].description);

            // battle loop
            int battle_over = 0;
            while (!battle_over) {
                // enemy attacks first
                printf("%s attacks!\n", enemies[enemy_index].name);
                for (int i = 0; i < MAX_CHARACTERS; i++) {
                    characters[i].health -= enemies[enemy_index].attack;
                    printf("%s takes %d damage!\n", characters[i].name, enemies[enemy_index].attack);
                }

                // check for game over
                int characters_alive = 0;
                for (int i = 0; i < MAX_CHARACTERS; i++) {
                    if (characters[i].health > 0) {
                        characters_alive = 1;
                        break;
                    }
                }
                if (!characters_alive) {
                    printf("Game over! All crew members have perished...\n");
                    game_over = 1;
                    battle_over = 1;
                    break;
                }

                // characters attack
                printf("Your crew attacks!\n");
                for (int i = 0; i < MAX_CHARACTERS; i++) {
                    if (characters[i].health > 0) {
                        enemies[enemy_index].health -= characters[i].attack;
                        printf("%s deals %d damage!\n", characters[i].name, characters[i].attack);
                    }
                }

                // check for enemy defeat
                if (enemies[enemy_index].health <= 0) {
                    printf("You have defeated the %s!\n\n", enemies[enemy_index].name);
                    characters[current_planet].resources += enemies[enemy_index].health; // add enemy health to resources
                    battle_over = 1;
                }
            }
        }

        // check for game over
        if (game_over) {
            break;
        }

        // ask player if they want to travel to a new planet
        char input[10];
        printf("Do you want to travel to a new planet? (y/n)\n");
        scanf("%s", input);
        if (strcmp(input, "y") == 0 || strcmp(input, "Y") == 0) {
            // choose a new planet
            int new_planet = random_number(1, MAX_PLANETS - 1);
            printf("You travel to %s...\n\n", planets[new_planet].name);

            // consume resources to travel
            characters[current_planet].resources -= planets[current_planet].distance;
            if (characters[current_planet].resources < 0) {
                printf("Game over! You have run out of resources...\n");
                game_over = 1;
                break;
            }

            current_planet = new_planet;
        }
    }

    // end of game
    printf("Thanks for playing!\n");

    return 0;
}