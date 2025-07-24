//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define FUEL_MAX 50
#define SHIP_MAX_HEALTH 100

// Define global variables
int map[MAP_WIDTH][MAP_HEIGHT];
int ship_x, ship_y;
int fuel = FUEL_MAX;
int health = SHIP_MAX_HEALTH;

// Function prototypes
void generate_map();
void print_map();
void move_ship(int x, int y);
void check_event();
void run_event(int event_type);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate map and place ship randomly
    generate_map();
    ship_x = rand() % MAP_WIDTH;
    ship_y = rand() % MAP_HEIGHT;
    map[ship_x][ship_y] = 1;

    // Game loop
    while (1) {
        // Print current status
        printf("Fuel: %d Health: %d\n", fuel, health);
        print_map();

        // Check for game over
        if (health <= 0) {
            printf("Game over! Your ship was destroyed.\n");
            break;
        } else if (fuel <= 0) {
            printf("Game over! You ran out of fuel.\n");
            break;
        }

        // Ask player for input
        char input;
        printf("Enter a direction to move (n/s/e/w): ");
        scanf(" %c", &input);

        // Parse input and move ship
        switch (input) {
            case 'n':
                move_ship(0, -1);
                break;
            case 's':
                move_ship(0, 1);
                break;
            case 'e':
                move_ship(1, 0);
                break;
            case 'w':
                move_ship(-1, 0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check for event
        check_event();
    }

    return 0;
}

// Generate random map
void generate_map() {
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = rand() % 5;
        }
    }
}

// Print map
void print_map() {
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            if (i == ship_x && j == ship_y) {
                printf("[*]"); // Show ship location
            } else {
                printf("[%d]", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Move ship and deduct fuel
void move_ship(int x, int y) {
    ship_x += x;
    ship_y += y;

    // Check for out-of-bounds move
    if (ship_x < 0 || ship_x >= MAP_WIDTH || ship_y < 0 || ship_y >= MAP_HEIGHT) {
        printf("You hit the edge of the universe!\n");
        health -= 25;
        return;
    }

    // Deduct fuel for movement
    fuel -= abs(x) + abs(y);
}

// Check for event at current location
void check_event() {
    int event_type = map[ship_x][ship_y];

    switch (event_type) {
        case 0:
            printf("Nothing interesting here.\n");
            break;
        case 1:
            printf("You found a planet with breathable air!\n");
            run_event(1);
            break;
        case 2:
            printf("You encountered a hostile alien race!\n");
            run_event(2);
            break;
        case 3:
            printf("Your ship found a mysterious artifact!\n");
            run_event(3);
            break;
        case 4:
            printf("Your ship was ambushed by space pirates!\n");
            run_event(4);
            break;
    }
}

// Run event based on event_type
void run_event(int event_type) {
    switch (event_type) {
        case 1:
            printf("You spend some time exploring the planet and find valuable resources.\n");
            fuel += 10;
            health += 10;
            break;
        case 2:
            printf("You engage in battle with the hostile aliens!\n");
            srand(time(NULL));
            int alien_health = rand() % 50 + 50;

            while (health > 0 && alien_health > 0) {
                // Player attacks alien
                int damage = rand() % 10 + 10;
                printf("You hit the alien for %d damage!\n", damage);
                alien_health -= damage;

                if (alien_health <= 0) {
                    printf("You defeated the aliens!\n");
                    break;
                }

                // Alien attacks player
                damage = rand() % 10 + 10;
                printf("The alien hits you for %d damage!\n", damage);
                health -= damage;
            }

            if (health <= 0) {
                printf("Your ship was destroyed in battle.\n");
            } else {
                printf("You survived the battle!\n");
                fuel += 20;
                health += 10;
            }
            break;
        case 3:
            printf("You examine the artifact and discover it is a powerful weapon!\n");
            printf("Your ship's weapons system is upgraded.\n");
            break;
        case 4:
            printf("You engage in battle with the space pirates!\n");
            srand(time(NULL));
            int pirate_health = rand() % 50 + 50;

            while (health > 0 && pirate_health > 0) {
                // Player attacks pirate
                int damage = rand() % 10 + 10;
                printf("You hit the pirate for %d damage!\n", damage);
                pirate_health -= damage;

                if (pirate_health <= 0) {
                    printf("You defeated the pirates!\n");
                    fuel += 30;
                    break;
                }

                // Pirate attacks player
                damage = rand() % 10 + 10;
                printf("The pirate hits you for %d damage!\n", damage);
                health -= damage;
            }

            if (health <= 0) {
                printf("Your ship was destroyed in battle.\n");
            } else {
                printf("You survived the battle!\n");
                fuel += 10;
                health += 10;
            }
            break;
    }
}