//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for game
#define NUM_PLANETS 10
#define MAX_DISTANCE 100
#define MIN_DISTANCE 10
#define MAX_ENEMIES 5

// Define struct for planets
struct Planet {
    int id;
    char name[20];
    int distance;
    int numEnemies;
};

int main() {
    srand(time(0));
    int player_health = 100;
    int player_ship_health = 100;
    int planets_visited = 0;
    int current_planet_index = -1;
    int enemies_defeated = 0;
    struct Planet planets[NUM_PLANETS];
    char input[10];

    // Create planet array
    for(int i = 0; i < NUM_PLANETS; i++) {
        planets[i].id = i;
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
        planets[i].numEnemies = rand() % (MAX_ENEMIES + 1);
    }

    printf("\t-----------------\n");
    printf("\t  Space Adventure\n");
    printf("\t-----------------\n");

    // Game loop
    while(player_health > 0) {
        printf("You are on Planet %d\n", current_planet_index+1);

        // Check if all planets have been visited
        if(planets_visited == NUM_PLANETS) {
            printf("Congratulations! You have visited all the planets.\n");
            break;
        }

        // Print planet options
        printf("Choose your destination:\n");
        for(int i = 0; i < NUM_PLANETS; i++) {
            // Check if planet has been visited
            if(planets[i].id <= planets_visited) {
                printf("%d. %s (Distance: %d)\n", planets[i].id+1, planets[i].name, planets[i].distance);
            } else {
                printf("%d. ???\n", planets[i].id+1);
            }
        }

        // Prompt for input
        printf("Enter your destination: ");
        fgets(input, 10, stdin);
        int choice = atoi(input) - 1;

        // Check if choice is valid
        if(choice < 0 || choice >= NUM_PLANETS) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Check if planet has been visited
        if(planets[choice].id > planets_visited) {
            printf("You do not have access to this planet yet. Please try again.\n");
            continue;
        }

        // Move to planet
        current_planet_index = choice;
        printf("You have traveled to %s.\n", planets[current_planet_index].name);

        // Check for enemies
        int num_enemies = planets[current_planet_index].numEnemies;
        if(num_enemies > 0) {
            printf("You have been encountered by %d enemy ships.\n", num_enemies);
            for(int i = 0; i < num_enemies; i++) {
                int enemy_health = rand() % 100;
                printf("Enemy ship %d has %d health.\n", i+1, enemy_health);

                // Fight enemy ship
                while(player_ship_health > 0 && enemy_health > 0) {
                    // Player turn
                    int player_damage = rand() % 50;
                    enemy_health -= player_damage;
                    printf("You inflict %d damage on the enemy ship. Enemy ship health: %d\n", player_damage, enemy_health);
                    if(enemy_health <= 0) {
                        printf("You have defeated the enemy ship.\n");
                        enemies_defeated++;
                        break;
                    }

                    // Enemy turn
                    int enemy_damage = rand() % 50;
                    player_ship_health -= enemy_damage;
                    printf("Enemy ship inflicts %d damage on your ship. Your ship health: %d\n", enemy_damage, player_ship_health);
                    if(player_ship_health <= 0) {
                        printf("Your ship has been destroyed.\n");
                        break;
                    }
                }
            }
        }

        // Update game state
        planets_visited++;
        player_health += rand() % 25;
        player_ship_health = 100;
    }

    printf("Game over. You visited %d planets and defeated %d enemies.\n", planets_visited, enemies_defeated);

    return 0;
}